##
## EPITECH PROJECT, 2020
## My_Runner by Timothy CONIEL
## File description:
## Makefile
##

CC		=	gcc	-o

SRC=		src/main.c		\
		src/lib.c		\
		src/map.c		\
		src/read.c		\
		src/error_handling.c	\

CFLAGS	=	-Wall	-Wextra	-pedantic	--std=c99 -Iinclude -g

NAME	=	crocus

all:
	$(CC)	$(NAME)	$(SRC)	$(CFLAGS)

clean:

fclean: clean
	rm	-f	$(NAME)

re:	fclean	make

.PHONY:	all	clean	fclean	re
