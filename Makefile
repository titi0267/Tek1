##
## EPITECH PROJECT, 2020
## CSFML
## File description:
## Makefile
##

SRC=	windo_disp.c

NAME=	hunter

OBJ=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc		$(SRC)	-o	$(NAME)	-l csfml-window -l csfml-graphics -l csfml-system

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:	fclean all