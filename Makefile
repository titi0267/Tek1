##
## EPITECH PROJECT, 2020
## My_Runner by Timothy CONIEL
## File description:
## Makefile
##
CC		=	gcc	-o

SRC=	src/antman.c	\
		src/usage.c		\
		src/compress.c	\
		src/compress_print.c	\
		src/file.c
SRCS=	src/giantman.c			\

CFLAGS	=	-Wall	-Wextra	-pedantic	--std=c99	-L./lib/my	-lmy	-I./include -g

NAME	=	antman
NAMES	=	giantman

all:
	${MAKE} -C lib/my/
	$(CC)	$(NAME)	$(SRC)	$(CFLAGS)
	$(CC)	$(NAMES) $(SRCS) $(CFLAGS)

clean:
	make	-C	lib/my/	clean

fclean: clean
	rm	-f	$(NAME)
	rm	-f	$(NAMES)
	make	-C	lib/my	fclean

re:	fclean

.PHONY:	all	clean	fclean	re