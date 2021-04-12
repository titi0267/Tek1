##
## EPITECH PROJECT, 2020
## B-PSU-100-STG-1-1-bsmyls-sylvian.burn
## File description:
## Makefile
##

SRC	=	main.c	\
		error.c

OBJ	=	$(SRC:.c=.o)

NAME	=	generator

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc	-g	$(OBJ)	-o	$(NAME)	-L../lib/my	-lmy

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all