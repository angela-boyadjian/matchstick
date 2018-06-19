/*
** EPITECH PROJECT, 2018
** player.c
** File description:
** player functions
*/
#include "matchstick.h"

static int	get_input_match(char *save, int *line, int *matches,
	struct game *match)
{
	my_putstr("Matches: ");
	save = get_next_line(0);
	if (!save)
		return (SUCCESS);
	if (my_str_isnum(save) == SUCCESS) {
		my_printf(INVALID);
		return (ERROR);
	}
	*matches = my_getnbr(save);
	if (check_input_match(match, line, matches) == false)
		return (ERROR);
	else
		return (VALID);
}

static int	get_input_line(char *save, int *line, int *matches,
	struct game *match)
{
	int	valid = 0;

	while (valid == SUCCESS) {
		my_putstr("Line: ");
		save = get_next_line(0);
		if (!save)
			return (SUCCESS);
		*line = my_getnbr(save);
		if (my_str_isnum(save) == SUCCESS) {
			my_printf(INVALID);
			valid = 0;
		}
		else if (check_input_line(match, line, matches) == false)
			valid = 0;
		else
			valid = 1;
	}
	return (VALID);
}

// Handles player
int	player(struct game *match)
{
	char	*save = NULL;
	int		line = 0;
	int		matches = 0;
	int		value = 0;

	my_printf("Your turn:\n");
	do {
		if (get_input_line(save, &line, &matches, match) == SUCCESS)
			return (ERROR);
		value = get_input_match(save, &line, &matches, match);
		if (value == SUCCESS)
			return (ERROR);
	} while (value != VALID);
	match->save[line - 1] -= matches;
	my_printf("Player removed %d match(es) from line %d\n",
	matches, line);
	print_map(match);
	check_victory(match);
	if (match->victory == true)
		return (end_game(VALID));
	return (SUCCESS);
}