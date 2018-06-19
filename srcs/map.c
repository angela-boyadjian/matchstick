/*
** EPITECH PROJECT, 2018
** map.c
** File description:
** map functions
*/
#include "matchstick.h"


static void	handle_print_sticks(struct game *match, int j, int count)
{
	for (int i = 0; i < match->len; ++i) {
		if (i == match->len / 2 - count)
			print_sticks(match, j, &i);
		else
			my_putchar(' ');
	}
}

// Prints the map
void	print_map(struct game *match)
{
	int	count = 1;

	print_line(match->len);
	for (int j = 0; j < match->nb[0]; ++j) {
		my_putchar('*');
		handle_print_sticks(match, j, count);
		my_putstr("*\n");
		++count;
	}
	print_line(match->len);
	my_putchar('\n');
}
