##
## EPITECH PROJECT, 2020
## Makefile by Elliot WALDVOGEL
## File description:
## Makefile
##

SRC = 	src/fs_open_file.c				\
		src/fs_understand_return_of_read.c	\
		src/store_car.c						\
		main.c

CC		=	gcc -lm

CFLAGS	=	-Wall -Wextra -pedantic --std=c99 -Llib/my -lmy -Iinclude -g

OBJS	=	$(SRC:.c=.o)

EXEC	=	bsq

all:	${EXEC}

${EXEC}: ${OBJS}
	${MAKE} -C lib/my/
	${CC} 	-o ${EXEC} ${OBJS} ${CFLAGS}

clean:
	rm -f ${OBJS}
	make -C lib/my/ clean

fclean: clean
	rm -f ${EXEC}
	make -C lib/my fclean

re:	fclean