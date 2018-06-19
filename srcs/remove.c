/*
** EPITECH PROJECT, 2017
** remove.c
** File description:
** remove functions
*/
#include "matchstick.h"

// Remove 1 matchstick
void	rm_one(struct game *match)
{
	int	i;

	for (i = 0; i != -1 && match->save[i] != 1; ++i);
	if (i != -1)
		match->save[i] -= 1;
	my_printf("AI removed 1 match(es) from line %d\n",
	i + 1);
}

// Check last matchstick
static int	check_last(struct game *match)
{
	int	count = 0;
	int	save = 0;

	for (int i = 0; match->save[i] != -1; ++i) {
		if (match->save[i] > 0) {
			++count;
			save = i;
		}
	}
	if (count == VALID)
		return (save);
	return (ERROR);
}

// Removes the first match found
void	rm_first_match(struct game *match)
{
	int	index = check_last(match);

	if (index != -1) {
		if (match->save[index] - match->nb[1] <= 1) {
			my_printf("AI removed %d match(es) from line %d\n",
			match->save[index] - 1, index + 1);
			match->save[index] = 1;
			return;
		}
	}
	for (int i = 0; match->save[i] != -1; ++i) {
		if (match->save[i] > 0) {
			match->save[i] -= 1;
			my_printf("AI removed 1 match(es) from line %d\n",
			i + 1);
			break;
		}
	}
}

// Returns the number of sticks to be removed
int	ret_sticks_line(int *algo, int sum, int j, struct game *match)
{
	int	nb = 0;

	for (int i = 0; algo[i] != -1; ++i) {
		nb = algo[i] ^ sum;
		if (j == 1 && nb < match->save[i]) {
			if (nb == SUCCESS)
				return (match->save[i]);
			return (nb);
		}
		else if (j == 0 && nb < match->save[i])
			return (i);
	}
	return (ERROR);
}

// Checks finishing move
bool	check_last_match(struct game *match)
{
	int	count = 0;

	for (int i = 0; match->save[i] != -1; ++i) {
		if (match->save[i] > 0)
			++count;
	}
	if (count == 1)
		return (true);
	return (false);
}
