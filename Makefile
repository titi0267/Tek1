##
## EPITECH PROJECT, 2020
## CSFML
## File description:
## Makefile
##

SRC=	windo_disp.c	\
		event.c			\
		duck.c			\
		reset_duck.c

NAME=	hunter

all:	$(NAME)

$(NAME):
	gcc		$(SRC)	-o	$(NAME)	-l csfml-window -l csfml-graphics -l csfml-system

clean:

fclean: clean
		rm -f $(NAME)

re:	fclean all