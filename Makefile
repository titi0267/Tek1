##
## EPITECH PROJECT, 2020
## B-CPE-100-STG-1-1-cpoolday11-sylvian.burn
## File description:
## Makefile
##

SRC	=	number.c

OBJ	=	$(SRC:.c=.o)

NAME	=	number

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my
	gcc $(OBJ) -o $(NAME) -L./lib/my -lmy

clean:
	make clean -C ./lib/my
	rm -f $(OBJ)

fclean:	clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re:	fclean all
