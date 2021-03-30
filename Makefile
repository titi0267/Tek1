##
## EPITECH PROJECT, 2020
## B-PSU-100-STG-1-1-bsmyls-sylvian.burn
## File description:
## Makefile
##

CC=	gcc	-o

SRC=	main2.c

NAME=	nothing

all:	$(NAME)

$(NAME):
	${MAKE} -C ./lib/my
	${MAKE} ./generator
	$(CC)	$(NAME)	$(SRC)

clean:
	${MAKE} clean -C ./lib/my
	${MAKE} clean -C ./generator

fclean: clean
	${MAKE} fclean -C ./lib/my
	${MAKE} fclean -C ./generator
	rm -f $(NAME)

re: fclean all