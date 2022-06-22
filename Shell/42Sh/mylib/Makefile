##
## EPITECH PROJECT, 2020
## libmy
## File description:
## first makefile
##

STR_SRC		=	$(wildcard ./my_str/*.c)

INC_DIR		=	../include/

CFLAGS		=	-I$(INC_DIR) -W -Wall

OBJ			=	$(STR_SRC:.c=.o)

NAME		=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar -crs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re: fclean all
