##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## 
##

CC		=	gcc	-o

<<<<<<< HEAD
SRC=		src/main.c \
		tools/my_put_nbr.c \
		tools/my_strlen.c \
		tools/my_getnbr.c \
		tools/my_putchar.c \
=======
SRC=		src/main.c		\
		src/lib.c		\
		src/map.c		\
		src/error_handling.c	\
		src/nbrline.c		\
		src/store.c		\
>>>>>>> 998b3b08fe8ad4047ae0371534014d3b5d2eace5

CFLAGS	=	-Wall	-Wextra	-pedantic	--std=c99 -Iinclude -g

NAME	=	mixword

all:
	$(CC)	$(NAME)	$(SRC)	$(CFLAGS)

clean:

fclean: clean
	rm	-f	$(NAME)

re:	fclean	make

.PHONY:	all	clean	fclean	re
