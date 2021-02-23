##
## EPITECH PROJECT, 2021
## B-MUL-200-STG-2-1-mydefender-timothe.coniel
## File description:
## Makefile
##

CC=	gcc	-o

SRC		=		Source/main.c 					\
				Source/Rigor/start_errors.c 	\
				Source/Start/initialize_wnd.c 	\
				Source/End/destroy.c 			\
				Source/Start/Create_spt/background.c	\
				Source/Game_core/wnd_open.c				\
				Source/Game_core/timer.c				\
				Source/Start/init_time.c				\
				Source/Start/init_regroup.c				\

CFLAGS	=	-Wall	-Wextra	-pedantic	--std=c99	-L./lib/my	-lmy	-I./include	-l csfml-audio -l csfml-graphics -l csfml-window -l csfml-system -g

NAME	=		my_defender

all:
		${MAKE}	-C	lib/my/
	$(CC)	$(NAME)	$(SRC)	$(CFLAGS)

clean:
		make	-C	lib/my/	clean

fclean:	clean
		rm -f $(NAME)
		make	-C	lib/my	fclean

re:		fclean all

.PHONY:	all	clean	fclean	re