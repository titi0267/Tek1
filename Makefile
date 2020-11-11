##
## EPITECH PROJECT, 2020
## PRINTF
## File description:
## Makefile
##

SRC =	src/main.c

CC		=	gcc

CFLAGS	=	-Wall	-Wextra	-pedantic	--std=c99	-Llib/my	-lmy	-Iinclude	-g

OBJS	=	$(SRC:.c=.o)

EXEC	=	printf

all:	${EXEC}

${EXEC}:	${OBJS}
	${MAKE}	-C	lib/my/
	${CC} 	-o	${EXEC}	${OBJS}	${CFLAGS}	-g

clean:
	rm	-f	${OBJS}
	make	-C	lib/my/	clean
		make	-C	clean


fclean: clean
	rm	-f	${EXEC}
	rm	-f	$(NAME)
	make	-C	lib/my	fclean
	make	-C	fclean

re:	fclean

.PHONY:	all	clean	fclean	re