/*
** EPITECH PROJECT, 2017
** special_case.c
** File description:
** special case functions
*/
#include "matchstick.h"

// Returns true if there's an even number of 1's else returns false
int	check_even_one(struct game *match, int res)
{
	int	nb = 0;

	if (res == SUCCESS)
		++nb;
	for (int i = 0; match->save[i] != -1; ++i) {
		if (match->save[i] == 1)
			++nb;
	}
	return (nb);
}

// Checks if column is valid
int	check_sticks_col(struct game *match)
{
	int	i;
	int	count = 0;
	int	save = 0;

	for (i = 0; match->save[i] != -1; ++i) {
		if (match->save[i] > 0 && save == SUCCESS)
			save = i;
		if (match->save[i] > 1) {
			++count;
			save = i;
		}
	}
	if (count > 1)
		return (ERROR);
	return (save);
}

static int	calc_res(struct game *match, int nb)
{
	int	res = 0;

	if (match->save[nb] - match->nb[1] <= 0)
		return (ERROR);
	res = ((match->save[nb] - (match->nb[1] + 2)) % match->nb[1]);
	return (res);
}

static void	manage_res(int res, struct game *match, int index)
{
	if (match->save[index] > 0 && res > 0) {
		match->save[index] -= res;
		my_printf("AI removed %d match(es) from line %d\n",
		res, index + 1);
	} else {
		match->save[index] -= match->nb[1];
		my_printf("AI removed %d match(es) from line %d\n",
		match->nb[1], index + 1);
	}
}

void	last_col(struct game *match, int index)
{
	int	res = calc_res(match, index);
	int	nb = check_even_one(match, res);

	if (res == -1 && nb == 1 && match->save[index] - match->nb[1] <= 0) {
		my_printf("AI removed %d match(es) from line %d\n",
		match->save[index], index + 1);
		match->save[index] = 0;
		return;
	}
	if (nb != 0 && (nb % 2) == 0)
		rm_one(match);
	else if (res >= 0)
		manage_res(res, match, index);
	else
		rm_first_match(match);
}