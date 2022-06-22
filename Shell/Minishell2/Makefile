##
## EPITECH PROJECT, 2020
## My_Runner by Timothy CONIEL
## File description:
## Makefile
##
CC		=	gcc	-o

SRC=	src/main.c			\
		src/simple_cmd.c	\
		src/change_dir.c	\
		src/un_env.c		\
		src/setenv.c		\
		src/unenv_cmd.c		\
		src/user_input.c	\
		src/builtin_cmd.c	\
		src/next_env.c		\
		src/env.c			\
		src/flags.c


CFLAGS	=	-Wextra	-pedantic	--std=c99	-L./lib/my	-lmy	-I./includes

NAME	=	mysh

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