##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## 
##

CC		=	gcc	-o

SRC=		src/main.c \
		tools/my_put_nbr.c \
		tools/my_strlen.c \
		tools/my_getnbr.c \
		tools/my_putchar.c \

CFLAGS	=	-Wall	-Wextra	-pedantic	--std=c99 -Iinclude -g

NAME	=	mixword

all:
	$(CC)	$(NAME)	$(SRC)	$(CFLAGS)

clean:

fclean: clean
	rm	-f	$(NAME)

re:	fclean	make

.PHONY:	all	clean	fclean	re
