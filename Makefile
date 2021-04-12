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
	${MAKE} -C ./generator
	${MAKE} -C ./solver
	$(CC)	$(NAME)	$(SRC)
	rm $(NAME)

clean:
	${MAKE} clean -C ./lib/my
	${MAKE} clean -C ./generator
	${MAKE} clean -C ./solver

fclean: clean
	${MAKE} fclean -C ./lib/my
	${MAKE} fclean -C ./generator
	${MAKE} fclean -C ./solver
	rm -f $(NAME)

re: fclean all