/*
** EPITECH PROJECT, 2017
** algo.c
** File description:
** algo function for ai
*/
#include "matchstick.h"

// Returns the size of an int *
int	get_size(int *tab)
{
	int	i;

	for (i = 0; tab[i] != -1; ++i);
	return (i);
}

// Returns the nim sum
int	nim_sum(int *algo)
{
	int	sum = 0;
	int	i;

	for (i = 0; algo[i] != -1; ++i) {
		if (i == 0) {
			sum = algo[i] ^ algo[i + 1];
		} else if (algo[i + 1] != -1) {
			sum = sum ^ algo[i + 1];
		}
	}
	return (sum);
}

// Returns an int * with line % (k + 1)
int	*do_modulo(struct game *match)
{
	int	*algo = malloc(sizeof(int) * get_size(match->save) + 1);
	int	i;

	for (i = 0; match->save[i] != -1; ++i)
		algo[i] = match->save[i] % (match->nb[1] + 1);
	algo[i] = -1;
	return (algo);
}

// Returns 1 if nim sum == 0
static int	check_sum(int *algo, struct game *match, int i)
{
	for (int j = 1; algo[i] - j >= 0;) {
		algo[i] -= j;
		if (nim_sum(algo) == 0) {
			match->save[i] -= j;
			my_printf("AI removed %d match(es) from line %d\n",
			j, i + 1);
			return (1);
		}
	}
	return (SUCCESS);
}

// Implementation of nim algorithm
void	algorithm(struct game *match)
{
	int	*algo = do_modulo(match);
	int	size = get_size(algo);
	int	save;

	if (nim_sum(algo) == SUCCESS) {
		rm_first_match(match);
		return;
	}
	for (int i = 0; i < size; ++i) {
		save = algo[i];
		if (check_sum(algo, match, i) == 1)
			return;
		algo[i] = save;
	}
}