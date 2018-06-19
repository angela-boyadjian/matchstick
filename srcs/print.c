/*
** EPITECH PROJECT, 2018
** print.c
** File description:
** printing functions
*/
#include "matchstick.h"

void	print_line(int len)
{
	for (int i = 0; i < len; ++i)
		my_putchar('*');
	my_putchar('\n');
}

void	print_sticks(struct game *match, int j, int *i)
{
	for (int count = 0; count < match->save[j]; ++count) {
		my_putchar('|');
		*i = *i + 1;
	}
	*i = *i + 1;
}