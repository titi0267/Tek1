##
## EPITECH PROJECT, 2020
## B-PSU-100-STG-1-1-myls-timothe.coniel
## File description:
## Makefile
##
CC=		gcc

SRC=	src/error_str.c		\
		src/main.c

NAME=	my_ls

all:
	${MAKE} -C lib/my/
	$(CC)	$(SRC)	-L./lib/my -lmy	-o	$(NAME)

clean:
	make -C lib/my/ clean

fclean:	clean
		make -C lib/my fclean
		rm	-f	$(NAME)

re:	fclean	all

.PHONY:	all	clean	fclean	re