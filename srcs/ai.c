/*
** EPITECH PROJECT, 2018
** lines.c
** File description:
** line function
*/
#include "matchstick.h"

// Function to handle ai
int	ai(struct game *match)
{
	int	index;

	my_putstr("AI's turn...\n");
	index  = check_sticks_col(match);
	if (index != -1)
		last_col(match, index);
	else
		algorithm(match);
	print_map(match);
	check_victory(match);
	if (match->victory == true)
		return (end_game(0));
	return (0);
}