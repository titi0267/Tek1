SRC=	infiniadd.c	\
	police.c	\
	police_norm.c	\
	operations.c

OBJ=	$(SRC:.c=.o)

CFLAGS=	-g

NAME=	infin_add

all:	$(NAME)

$(NAME):	$(OBJ)
	make	-C	../lib/my
	gcc		-o	$(NAME)	$(OBJ)	-I./include/	-L../lib/my -lmy


clean:
	rm	-f	$(OBJ)
fclean:	clean
	rm	-f	$(NAME)
re:	fclean	all
