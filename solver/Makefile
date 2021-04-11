##
## EPITECH PROJECT, 2020
## B-PSU-100-STG-1-1-bsmyls-sylvian.burn
## File description:
## Makefile
##

CC=	gcc	-o

SRC	=	main.c		\
		read_file.c

NAME	=	solver

CFLAGS=	-L../lib/my -lmy

all:
	$(CC)	$(NAME)	$(SRC)	$(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all