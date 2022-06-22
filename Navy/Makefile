##
## EPITECH PROJECT, 2020
## Makefile by Elliot WALDVOGEL
## File description:
## Makefile
##

SRC = 	src/navy.c				\
		src/connection.c		\
		src/map.c				\
		src/position.c			\
		src/place_ship.c		\
		src/match_case.c		\
		src/game_core.c			\
		src/encryption.c		\
		src/shots_managements.c	\
		src/handle_sigusr.c		\

CC		=	gcc -o -lm

CFLAGS	=	-Wall -Wextra -pedantic --std=c99 -Llib/my -lmy -Iinclude

OBJS	=	$(SRC:.c=.o)

EXEC	=	navy

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

.PHONY: all clean fclean re