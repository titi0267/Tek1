##
## EPITECH PROJECT, 2021
## B-MUL-200-STG-2-1-mydefender-timothe.coniel
## File description:
## Makefile
##

CC=	gcc	-o

SRCSPATH = src/

SRCSFILES	=	main.c 				\
				error_args.c		\
				print_map.c			\
				user_input.c		\
				change_map.c		\
				error_usr_input.c	\
				ai.c				\
				check_win.c			\

SRCS = $(addprefix $(SRCSPATH), $(SRCSFILES))

CFLAGS	=	-Wall	-Wextra	-pedantic	--std=c99	-L./lib/my	-lmy	-I./include -g

NAME	=		matchstick

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