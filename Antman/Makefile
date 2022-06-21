##
## EPITECH PROJECT, 2020
## My_Runner by Timothy CONIEL
## File description:
## Makefile
##
CC		=	gcc	-o

SRC=	ant_src/antman.c						\
		ant_src/usage.c							\
		ant_src/create_list.c					\
		ant_src/frequency.c						\
		ant_src/print_compress.c				\
		ant_src/error_handling.c				\
		ant_src/file.c							\
		ant_src/huffmansbox.c

SRCS=	giant_src/giantman.c					\
		giant_src/file.c						\
		giant_src/usage.c						\
		giant_src/recreate_tree.c				\
		giant_src/error_handling.c				\
		giant_src/decompression.c				\
		giant_src/huffmanstree.c				\
		giant_src/huffmanstree_bis.c			\
		giant_src/bindecode.c

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