CC=	gcc

CFLAGS=	-g

SRC=	my_lists.c	\
		show.c	\
		polish.c

OBJ=	$(SRC:.c=.o)

NAME=	eval_expr

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy

clean:	
	rm $(OBJ)
fclean:	clean
	rm $(NAME)
re:	fclean all

.PHONY: all clean fclean all