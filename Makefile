##
## EPITECH PROJECT, 2020
## My_Runner by Timothy CONIEL
## File description:
## Makefile
##
CC		=	gcc	-o

SRC=	src/main.c		\
		src/display.c	\
		src/paralax.c	\
		src/bird.c		\
		src/set_background.c	\
		src/collision.c		\
		src/event.c		\
		src/moving_sprite.c		\
		src/bird_jump.c		\
		src/map.c

CFLAGS	=	-Wall	-Wextra	-pedantic	--std=c99	-L./lib/my	-lmy	-I./include	-l csfml-window -l csfml-graphics -l csfml-system

NAME	=	my_runner

all:
	${MAKE} -C lib/my/
	$(CC)	$(NAME)	$(SRC)	$(CFLAGS)

clean:
	make	-C	lib/my/	clean

fclean: clean
	rm	-f	$(NAME)
	make	-C	lib/my	fclean

re:	fclean

.PHONY:	all	clean	fclean	re