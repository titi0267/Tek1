##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## make
##

SRC	= 	main.c \
		src/error_handling.c \
		src/my_strlen.c \
		src/my_putstr.c \
		src/my_put_nbr.c \
		src/my_putchar.c \
		src/my_getnbr.c \
		src/fractal_zero.c \
		src/fractal_two.c \ 

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
