##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC		=	gcc	-o

SRC=		src/main.c		\
		src/error.c		\
		src/map.c		\
		src/nbrline.c		\
		src/lib.c		\
		src/user_input.c	\
		src/my_strcmp.c		\
		src/replace_star.c	\


CFLAGS	=	-Wall	-Wextra	-pedantic	--std=c99 -Iinclude -g

NAME	=	hangman

all:
	$(CC)	$(NAME)	$(SRC)	$(CFLAGS)

clean:

fclean: clean
	rm	-f	$(NAME)

re:	fclean	make

.PHONY:	all	clean	fclean	re
