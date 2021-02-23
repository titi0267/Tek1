##
## EPITECH PROJECT, 2021
## B-MUL-200-STG-2-1-mydefender-timothe.coniel
## File description:
## Makefile
##

CC=	gcc	-o

SRCSPATH = Source/

SRCSFILES	=	main.c 			\
				Rigor/start_errors.c 		\
				Start/malloc.c					\
				Start/Create_spt/background.c	\
				Start/initialize_wnd.c 			\
				Start/init_regroup.c			\
				Start/init_time.c				\
				Game_core/wnd_open.c				\
				Game_core/timer.c					\
				End/destroy.c 			\

SRCS = $(addprefix $(SRCSPATH), $(SRCSFILES))

CFLAGS	=	-Wall	-Wextra	-pedantic	--std=c99	-L./lib/my	-lmy	-I./include	-l csfml-audio -l csfml-graphics -l csfml-window -l csfml-system -g

NAME	=		my_defender

all:
		${MAKE}	-C	lib/my/
	$(CC)	$(NAME)	$(SRCS)	$(CFLAGS)

clean:
		make	-C	lib/my/	clean

fclean:	clean
		rm -f $(NAME)
		make	-C	lib/my	fclean

re:		fclean all

.PHONY:	all	clean	fclean	re