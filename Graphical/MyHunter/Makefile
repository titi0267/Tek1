##
## EPITECH PROJECT, 2020
## CSFML
## File description:
## Makefile
##

SRC=	src/display.c	\
		src/event.c			\
		src/duck.c			\
		src/reset_duck.c

NAME=	hunter

all:	$(NAME)

$(NAME):
	gcc		$(SRC)	-o	$(NAME)	-I./include -I./../../../../Downloads/CSFML-2.6.0/include	-l csfml-window -l csfml-graphics -l csfml-system

clean:

fclean: clean
		rm -f $(NAME)

re:	fclean all

.PHONY:	all	clean	fclean	re