##
## EPITECH PROJECT, 2020
## Untitled (Workspace)
## File description:
## Makefile
##

SRC=		my_putchar.c		\
			my_put_nbr.c		\
			my_putstr.c			\
			disp_str.c			\
			flag_array.c		\
			disp_stdarg.c		\
			disp_nbr.c			\
			disp_percent.c		\
			disp_unsigned.c		\
			disp_bin.c			\
			my_put_uint.c		\
			my_putnbr_base.c	\
			disp_oct.c			\
			disp_hex.c			\
			store_strlen.c		\
			disp_char.c

CFLAGS	=	-Wall	-Wextra	-pedantic	--std=c99	-Llib/my	-lmy	-Iinclude	-g

SRCSPATH	=	lib/my/

SRCS = $(addprefix $(SRCSPATH), $(SRC))

OBJ		=	$(SRCS:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		ar	rc	$(NAME)		$(OBJ)
		cp	lib/my/my.h		include/my.h
		cp	lib/my/my_struct.h		include/my_struct.h

clean:
		rm	-f	$(OBJ)

fclean:	clean
		rm	$(NAME)

re:		fclean	all

.PHONY:	all	clean	fclean	re