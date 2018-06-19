/*
** EPITECH PROJECT, 2018
** save.c
** File description:
** save map
*/
#include "matchstick.h"

void	display_save(int *save)
{
	int	i;

	for (i = 0; save[i] != -1; ++i)
		my_printf("line : %d has %d sticks\n", i, save[i]);
	my_printf("line : %d has %d sticks\n", i, save[i]);
}

int	*save_map(struct game *match)
{
	int	*save = malloc((sizeof(*save) * match->nb[0]) + 1);
	int	j = 1;
	int	i;

	if (!save)
		return (NULL);
	for (i = 0; i < match->nb[0]; ++i) {
		save[i] = j;
		j += 2;
	}
	save[i] = ERROR;
	return (save);
}