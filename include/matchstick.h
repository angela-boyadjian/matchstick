/*
** EPITECH PROJECT, 2018
** matchstick.h
** File description:
** matchstick header file
*/
#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include "printf.h"
#include "my.h"
#include "get_next_line.h"
#include <time.h>

#define SUCCESS 0
#define FAILURE 84
#define INVALID "Error: invalid input (positive number expected)\n"
#define	ERROR	-1
#define	VALID	1

struct game {
	int	*nb;
	int	len;
	int	*save;
	bool	victory;
};

/*
** Display
*/
void	print_sticks(struct game *match, int j, int *i);
void	print_line(int len);
void	print_map(struct game *match);
void	display_save(int *save);
void	print_stars(int *sticks, int *nb, int j);

/*
** Algorithm
*/
void	algorithm(struct game *match);
int		ai(struct game *match);
int		nim_sum(int *algo);
int		*do_modulo(struct game *match);
int		ret_sticks_line(int *algo, int sum, int j, struct game *match);
int		special_case(struct game *match);
bool	check_move(struct game *match, int *algo, int sum);
int		check_even_one(struct game *match, int res);
int		one(struct game *match);
void	handle_one(struct game *match);
int		check_sticks_col(struct game *match);
void	last_col(struct game *match, int index);

/*
** Game
*/
int		player(struct game *match);
int		andthewinneris(int player);
int		check_victory(struct game *match);
int		end_game(int player);

/*
** Error handling
*/
int		errors(int ac, char **av);
bool	check_input_line(struct game *match, int *line, int *matches);
bool	check_input_match(struct game *match, int *line, int *matches);

/*
** Remove
*/
void	rm_one(struct game *match);
void	rm_first_match(struct game *match);

/*
** Utils
*/
int		*save_map(struct game *match);
int		get_size(int *tab);

#endif