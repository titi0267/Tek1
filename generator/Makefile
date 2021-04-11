##
## EPITECH PROJECT, 2020
## B-PSU-100-STG-1-1-bsmyls-sylvian.burn
## File description:
## Makefile
##

CC=	gcc	-o

SRC	=	main.c	\
		error.c

NAME	=	generator

CFLAGS=	-L../lib/my -lmy

all:
	$(CC)	$(NAME)	$(SRC)	$(CFLAGS)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all