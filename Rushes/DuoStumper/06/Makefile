##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC		=	gcc	-o

SRC=		src/main.c		\
		src/my_strlen.c		\
		src/error_handling.c	\
		src/flags.c


CFLAGS	=	-Wall	-Wextra	-pedantic	--std=c99 -Iinclude

NAME	=	text_count

all:
	$(CC)	$(NAME)	$(SRC)	$(CFLAGS)

clean:

fclean: clean
	rm	-f	$(NAME)

re:	fclean	make

.PHONY:	all	clean	fclean	re
