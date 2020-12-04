##
## EPITECH PROJECT, 2020
## B-CPE-110-STG-1-1-pushswap-timothe.coniel
## File description:
## Makefile
##

CC=	gcc

SRC=	src/which_op.c		\
		src/my_lib.c		\
		src/create_list.c	\
		src/op_seclist.c		\
		src/main.c

NAME=	pushswap

all:
	$(CC)	$(SRC)	-o	$(NAME)

clean:

fclean:	clean
		rm -f	$(NAME)

re:	fclean	all

.PHONY:	all	clean	fclean	re
