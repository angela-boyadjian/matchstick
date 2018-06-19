/*
** EPITECH PROJECT, 2018
** errors.c
** File description:
** error handling
*/
#include "matchstick.h"

// Checks if line input is valid
bool	check_input_line(struct game *match, int *line, int *matches)
{
	if (*line <= 0 || match->save[*line - 1] <= 0
	|| match->save[*line - 1] - *matches < 0 || *line > match->nb[0]) {
		*line = 0;
		my_printf("Error: this line is out of range\n");
		return (false);
	}
	return (true);
}

// Checks if match input is valid
bool	check_input_match(struct game *match, int *line, int *matches)
{
	if (*matches <= 0) {
		my_printf("Error: you have to remove at least one match\n");
		return (false);
	}
	if (*matches > match->nb[1]) {
		*matches = 0;
		my_putstr("Error: you cannot remove more than ");
		my_printf("%d matches per turn\n", match->nb[1]);
		return (false);
	}
	if (match->save[*line - 1] - *matches < 0) {
		*matches = 0;
		my_printf("Error: not enough matches on this line\n");
		return (false);
	}
	return (true);
}

// Checks if parameters are correct
static int	check_value(int nb)
{
	if (nb <= 1 || nb >= 100)
		return (FAILURE);
	return (SUCCESS);
}

// Error handling
int	errors(int ac, char **av)
{
	if (ac != 3)
		return (FAILURE);
	if (my_str_isnum(av[1]) == 0 || my_str_isnum(av[2]) == 0)
		return (FAILURE);
	if (check_value(my_getnbr(av[1])) == FAILURE || my_getnbr(av[2]) <= 0)
		return (FAILURE);
	return (SUCCESS);
}