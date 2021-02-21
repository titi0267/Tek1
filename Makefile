##
## EPITECH PROJECT, 2020
## My_Runner by Timothy CONIEL
## File description:
## Makefile
##
CC		=	gcc	-o

SRC=	src/main.c			\
		src/on_target.c		\
		src/player.c		\
		src/restart_gm.c	\
		src/press_key.c		\
		src/error_handler.c	\
		src/assemble.c		\
		src/get_map.c		\
		src/map_elements.c	\
		src/loosing_cond/win_or_loose.c	\
		src/loosing_cond/corner.c		\
		src/loosing_cond/down_border.c	\
		src/loosing_cond/up_border.c	\
		src/loosing_cond/right_border.c	\
		src/loosing_cond/left_border.c	\
		bonus/quit.c	\

CFLAGS	=	-Wall	-Wextra	-pedantic	--std=c99	-L./lib/my	-lmy	-I./include	-lncurses -g

NAME	=	my_sokoban

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