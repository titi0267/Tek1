SRC=	infiniadd.c	\
	police.c	\
	police_norm.c	\
	operations.c

OBJ=	$(SRC:.c=.o)

CFLAGS=	-g

NAME=	libbistro.a

all:	$(NAME)

$(NAME):	$(OBJ)
    
	gcc	-c -o	$(NAME)	$(OBJ)	-I./include/	-L../lib/my -lmy
	ar rc libbistro.a $(OBJ)


clean:
	rm	-f	$(OBJ)
fclean:	clean
	rm	-f	$(NAME)
re:	fclean	all
