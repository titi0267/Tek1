##
## EPITECH PROJECT, 2020
## B-PSU-100-STG-1-1-bsmyls-sylvian.burn
## File description:
## Makefile
##

CC=	gcc	-o

SRC	=	generator.c	\
		error.c	\
		up.c	\
		down.c	\
		right.c	\
		left.c	\
		linked_list.c	\
		checks.c	\
		checks2.c	\
		create_maze.c

NAME	=	generator

CFLAGS=	-L../lib/my -lmy -g

all:
	$(CC)	$(NAME)	$(SRC)	$(CFLAGS)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all