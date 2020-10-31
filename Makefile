CC=	gcc

CFLAGS=	-g
SRC=	./evalexpr/evalexpr.c	\
	./evalexpr/polish.c	\
	./evalexpr/show.c	\
	./src_div/div_help.c	\
	./src_infadd/infiniadd.c	\
	./src_infadd/operations.c	\
	./src_infadd/police.c	\
	./src_infadd/police_norm.c	\
	./src_infsubst/infsubst.c	\
	./src_mult/mult.c

OBJ=	$(SRC:.c=.o)

NAME=	calc

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C ./lib/my
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy

clean:
	$(MAKE) clean -C ./lib/my
	rm -f $(OBJ)
fclean:	clean
	$(MAKE) fclean -C ./lib/my
	rm -f $(NAME)
re:	fclean all

.PHONY:	all clean fclean
