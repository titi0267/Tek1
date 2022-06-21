##
## EPITECH PROJECT, 2020
## B-PSU-100-STG-1-1-bsmyls-sylvian.burn
## File description:
## Makefile
##

CC=	gcc	-o

SRC	=	main.c		\
		init_end.c	\
		number_map.c	\
		print_path.c	\
		check_one.c		\
		check_two.c		\
		read_file.c		\
		check_next.c	\
		error_entry.c

NAME	=	solver

CFLAGS=	-L../lib/my -lmy -g

all:
	$(CC)	$(NAME)	$(SRC)	$(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all