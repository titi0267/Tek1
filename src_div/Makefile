CC=	gcc



SRC=	../src_mult/mult.c	\
	    div_help.c

OBJ=	$(SRC:.c=.o)

NAME=	div

all:	$(NAME)
	
$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -L../include/ -lbistro -L../lib/my -lmy
clean:
	rm $(OBJ)
fclean:	clean
	rm $(NAME)

.PHONY:	all clean fclean
