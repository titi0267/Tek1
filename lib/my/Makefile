##
## EPITECH PROJECT, 2020
## Untitled (Workspace)
## File description:
## Makefile
##

SRC=		my_getnbr.c		\
			my_putchar.c	\
			my_put_nbr.c	\
			my_putstr.c		\
			my_strlen.c		\
			print_float.c	\
			disp_str.c		\
			disp_char.c

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(OBJ)
		ar	rc	$(NAME)		$(OBJ)
		cp	my.h	../../include/my.h

clean:
		rm	-f	$(OBJ)

fclean:	clean
		rm	$(NAME)

re:		fclean	all