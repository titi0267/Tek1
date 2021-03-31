##
## EPITECH PROJECT, 2021
## B-MUL-200-STG-2-1-myrpg-timothe.coniel
## File description:
## Makefile
##

SRC	= 	src/rpg.c							\
		src/graphics/main_menu.c			\
		src/graphics/start.c				\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

all:	$(NAME)

CFLAGS += -g

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)