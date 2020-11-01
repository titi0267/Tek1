CC=	gcc

CFLAGS= -g


SRC=	../src_mult/mult.c	\
        ../src_infsubst/infsubst.c	\
	    ./div_help.c	\
		./infdiv.c	\
		./infmodul.c	\
		../src_infadd/infiniadd.c 	\
		../src_infadd/police.c	\
		../src_infadd/police_norm.c	\
		../src_infadd/operations.c	

OBJ=	$(SRC:.c=.o)

NAME=	div

all:	$(NAME)
	
$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -L../lib/my -lmy
clean:
	rm $(OBJ)
fclean:	clean
	rm $(NAME)

.PHONY:	all clean fclean
