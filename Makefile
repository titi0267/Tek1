##
## EPITECH PROJECT, 2020
## My_Runner by Timothy CONIEL
## File description:
## Makefile
##
CC		=	gcc	-o

SRC=	ant_src/antman.c						\
		ant_src/usage.c							\
		ant_src/compress.c						\
		ant_src/compress_print.c				\
		ant_src/error_handling.c				\
		ant_src/file.c

SRCS=	giant_src/giantman.c					\
		giant_src/file.c						\
		giant_src/file_bis.c					\
		giant_src/usage.c						\
		giant_src/decompress.c					\
		giant_src/decompress_print.c			\
		giant_src/error_handling.c

CFLAGS	=	-Wall	-Wextra	-pedantic	--std=c99	-L./lib/my	-lmy	-I./include -g

NAME	=	antman
##NAMES	=	giantman

all:
	${MAKE} -C lib/my/
	$(CC)	$(NAME)	$(SRC)	$(CFLAGS)
##	$(CC)	$(NAMES) $(SRCS) $(CFLAGS)

clean:
	make	-C	lib/my/	clean

fclean: clean
	rm	-f	$(NAME)
##	rm	-f	$(NAMES)
	make	-C	lib/my	fclean

re:	fclean

.PHONY:	all	clean	fclean	re