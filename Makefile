##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## make
##

SRC	= 	main.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	fractals

CFLAGS	+=	-Wall	-Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f	$(OBJ)

fclean:	clean
	rm -f	$(NAME)

re:	fclean all

.PHONY: all clean fclean re
