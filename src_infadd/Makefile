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
	mv -f libbistro.a ../src_mult/include

# cl: $(OBJ)
# 	gcc -o	$(NAME)	$(OBJ)	-I./include/	-L../lib/my -lmy


clean:
	rm	-f	$(OBJ)
fclean:	clean
	rm	-f	$(NAME)
re:	fclean	all
