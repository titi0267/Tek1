##
## EPITECH PROJECT, 2020
## My_Runner by Timothy CONIEL
## File description:
## Makefile
##
SRC=	src/test.c

CC		=	gcc -o

CFLAGS	=	-Wall	-Wextra	-pedantic	--std=c99	-Iinclude

EXEC	=	my_runner

all:	${EXEC}

${EXEC}: ${SRC}
	${MAKE}	-C	lib/my/
	${CC}	${EXEC}	-L.	-lmy	${CFLAGS}

clean:
	make	-C	lib/my/	clean

fclean: clean
	rm	-f	${EXEC}
	make	-C	lib/my	fclean

re:	fclean

.PHONY:	all	clean	fclean	re