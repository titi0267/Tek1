##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## make
##

SRC	= 	main.c \
		tools/my_strlen.c \
		tools/my_putstr.c \
		tools/my_put_nbr.c \
		tools/my_putchar.c \
		tools/my_getnbr.c \
		src/error_handling.c \
		src/fractal_zero.c \
		src/fractal_two.c

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
