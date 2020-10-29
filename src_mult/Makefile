CC=	gcc

SRC=	mult.c	

OBJ=	$(SRC:.c=.o)

NAME=	mult

all: $(NAME)

$(NAME):	$(OBJ) 
		gcc -o $(NAME) $(OBJ) -L./include -lbistro  -L../lib/my -lmy

clean:
	rm -f $(OBJ)

