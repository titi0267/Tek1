##
## EPITECH PROJECT, 2020
## ggg
## File description:
## ggg
##

CC=	gcc


SRC=	arr_to_num.c    \
		my_compute_square_root.c    \
		my_find_prime_sup.c \
		my_getnbr.c \
		my_is_prime.c   \
		my_isneg.c  \
		my_pow.c    \
		my_put_nbr.c    \
		my_putchar.c    \
		my_putstr.c \
		my_revstr.c \
		my_showstr.c    \
		my_sort_int_array.c \
		my_str_isalpha.c    \
		my_str_islower.c    \
		my_str_isnum.c  \
		my_str_isprintable.c    \
		my_str_isupper.c    \
		my_strcapitalize.c  \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strlen.c \
		my_strlowcase.c \
		my_strncmp.c    \
		my_strncpy.c    \
		my_strstr.c \
		my_strupcase.c  \
		my_swap.c   \
		my_strdup.c	\
		my_eexpr.c	\
		my_signw.c	\
		my_ntchar.c


OBJ=	$(SRC:.c=.o)

NAME=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	$(MAKE) clean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f libmy.a

.PHONY: all clean fclean