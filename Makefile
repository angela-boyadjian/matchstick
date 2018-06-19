##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## A Makefile for projetcs
##

CC	=	gcc -g3

RM	=	rm -rf

CFLAGS	+=	-Wall -Wextra

CFLAGS	+=	-I./include

NAME	=	matchstick

SRCS	=	srcs/main.c \
		srcs/map.c \
		srcs/special_case.c \
		srcs/print.c \
		srcs/end_game.c \
		srcs/remove.c \
		srcs/nim_algo.c \
		srcs/player.c \
		srcs/errors.c \
		srcs/save.c \
		srcs/ai.c

OBJS	=	$(SRCS:.c=.o)

LIB =		-L./lib -lmy

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./lib/my
	$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJS)
	make -C ./lib/my clean

fclean: clean
	$(RM) $(NAME)
	$(RM) lib/libmy.a
	make -C ./lib/my fclean


re: fclean all

.PHONY: all clean fclean re