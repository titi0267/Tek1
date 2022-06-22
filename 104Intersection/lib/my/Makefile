##
## EPITECH PROJECT, 2020
## Makefile by Elliot WALDVOGEL
## File description:
## Makefile
##

SRC	=	my_putchar.c	\
		my_put_nbr.c	\
		my_getnbr.c		\
		my_char_isnum.c		\
		my_puterr.c		\
		my_putcerr.c	\
		my_strcmp.c		\
		my_strcpy.c		\
		my_printf.c		\
		my_put_nbr_u.c	\
		my_putchari.c	\
		my_putnbr_base_u.c	\
		my_putnbr_base.c	\
		my_putnbr_base_width_u.c	\
		my_putnbr_base_width.c		\
		my_strlen.c		\
		my_putstr.c		\
		annex1.c		\
		my_intlen.c		\
		annex2.c		\
		annex3.c		\



OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp libmy.a ../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all