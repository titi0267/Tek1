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

CFLAGS =	-L./lib/my	-lmy	-I./include	-l	csfml-window	-l	csfml-graphics	-l	csfml-system	-l	csfml-audio

NAME	=		my_defender

all:
		${MAKE}	-C	lib/my/
		$(CC) $(NAME) $(SRC) $(CFLAGS)

clean:
		make	-C	lib/my/	clean

fclean:	clean
		rm -f $(NAME)
		make	-C	lib/my	fclean

re:		fclean all

.PHONY:	all	clean	fclean	re