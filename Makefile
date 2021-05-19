##
## EPITECH PROJECT, 2021
## minishell2
## File description:
## makefile
##

SRC		=	src/main.c					\
			src/env.c					\
			src/env_utils.c				\
			src/utils.c					\
			src/input/input.c			\
			src/input/commands.c		\
			src/cmd/args.c				\
			src/cmd/builtins.c			\
			src/cmd/commands.c			\
			src/cmd/redirections.c		\
			src/cmd/file_redirections.c	\
			src/cmd/pipe_redirections.c	\
			src/cmd/heredoc.c			\
			src/cmd/execute.c			\
			src/cmd/binary.c			\
			src/cmd/utils.c

INC_DIR	=	./include
LIB_DIR	=	./mylib

CFLAGS	=	-W -Wall -I$(INC_DIR) -g

OBJ		=	$(SRC:.c=.o)

NAME	=	42sh

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C $(LIB_DIR)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIB_DIR) -lmy

debug:	CFLAGS += -g
debug:	re

clean:
	make -C $(LIB_DIR) clean
	rm -rf $(OBJ)

fclean:	clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re:	fclean all
