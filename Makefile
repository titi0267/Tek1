##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## 
##

CC		=	gcc	-o

SRC=		src/main.c		\
		src/lib.c		\
		src/map.c		\
		src/nbrline.c		\
		src/store.c		\
		src/read.c		\


CFLAGS	=	-Wall	-Wextra	-pedantic	--std=c99 -Iinclude -g

NAME	=	mixword

all:
	$(CC)	$(NAME)	$(SRC)	$(CFLAGS)

clean:

fclean: clean
	rm	-f	$(NAME)

re:	fclean	make

.PHONY:	all	clean	fclean	re
