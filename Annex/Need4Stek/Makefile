##
## EPITECH PROJECT, 2020
## Makefile by Elliot WALDVOGEL
## File description:
## Makefile
##

SRC = 	src/info_getter.c		\
		src/error_handling.c	\
		src/ai.c				\
		src/main.c				\
		src/my_str_to_word_array.c		\

CC		=	gcc -o -lm

CFLAGS	=	-Wall -Wextra -pedantic --std=c99 -Llib/my -lmy -Iinclude -g

OBJS	=	$(SRC:.c=.o)

EXEC	=	ai

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

re:	fclean all