##
## EPITECH PROJECT, 2020
## B-MUL-100-STG-1-1-myrunner-timothe.coniel
## File description:
## Makefile
##

SRC=	my_putchar.c					\
		my_putstr.c						\
		my_putnbr.c						\
		my_revstr.c						\
		my_strncmp.c					\
		my_strlen.c						\
		my_getnbr.c						\
		my_int_to_str.c					\
		my_puterr.c						\
		my_putcerr.c					\
		pushswap/src_psw/which_op.c		\
		pushswap/src_psw/my_lib.c		\
		pushswap/src_psw/create_list.c	\
		pushswap/src_psw/op_seclist.c	\
		pushswap/src_psw/pushswap.c		\
		pushswap/bonus/print_list.c		\
		pushswap/src_psw/main.c			\
		printf/disp_adress.c			\
		printf/disp_bin.c				\
		printf/disp_char.c				\
		printf/disp_hex.c				\
		printf/disp_nascii.c			\
		printf/disp_nbr.c				\
		printf/disp_oct.c				\
		printf/disp_str.c				\
		printf/disp_strlen.c			\
		printf/disp_uint.c				\
		printf/flag.c					\
		printf/my_convert_base.c		\
		printf/my_printf.c				\
		printf/my_putcharp.c			\
		printf/my_putnbrp.c				\
		printf/my_putstrp.c				\
		printf/my_putuint.c				\
		printf/my_strcpyp.c

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(OBJ)
		ar	rc	$(NAME)		$(OBJ)
		cp	$(NAME)	../../

clean:
		rm	-f	$(OBJ)

fclean:	clean
		rm	$(NAME)
		rm ../../$(NAME)

re:		fclean	all

.PHONY:	all	clean	fclean	re