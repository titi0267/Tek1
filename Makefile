##
## EPITECH PROJECT, 2020
## My_Runner by Timothy CONIEL
## File description:
## Makefile
##
CC		=	gcc	-o

SRC=	src/main.c		\
		src/next_main.c

CFLAGS	=	-Wall	-Wextra	-pedantic	--std=c99	-I./include

NAME	=	anagram

all:
	$(CC)	$(NAME)	$(SRC)	$(CFLAGS)

clean:

fclean: clean
	rm	-f	$(NAME)

re:	fclean

.PHONY:	all	clean	fclean	re
