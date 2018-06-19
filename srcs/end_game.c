/*
** EPITECH PROJECT, 2018
** end_game.c
** File description:
** end game functions
*/
#include "matchstick.h"

// Checks if there's a victory
int	check_victory(struct game *match)
{
	int	i;

	for (i = 0; i < match->nb[0]; ++i) {
		if (match->save[i] > 0)
			return (SUCCESS);
	}
	match->victory = true;
	return (SUCCESS);
}

// Handles end of the game
int	end_game(int player)
{
	if (player == SUCCESS) {
		my_putstr("I lost... snif... but I'll get you next time!!\n");
		return (VALID);
	}
	my_putstr("You lost, too bad...\n");
	return (2);
}