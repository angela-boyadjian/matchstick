/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main function
*/
#include "matchstick.h"

static void	init_struct(struct game *match, char **av)
{
	match->nb = malloc(sizeof(int) * 2);
	match->nb[0] = my_getnbr(av[1]);
	match->nb[1] = my_getnbr(av[2]);
	match->save = save_map(match);
	match->len = match->save[match->nb[0] - 1] + 2;
	match->victory = false;
}

static int	save_tricks(int save)
{
	if (save == ERROR)
		return (SUCCESS);
	if (save == VALID)
		return (VALID);
	if (save == 2)
		return (2);
	return (FAILURE);
}

int	main(int ac, char **av)
{
	struct game	match;
	int		save;
	int		count = 0;

	if (errors(ac, av) == FAILURE)
		return (FAILURE);
	init_struct(&match, av);
	print_map(&match);
	while (match.victory == false) {
		if (count++ % 2 == 0)
			save = player(&match);
		else
			save = ai(&match);
		if (save == ERROR || save == VALID || save == 2)
			return (save_tricks(save));
	}
	return (SUCCESS);
}