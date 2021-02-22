##
## EPITECH PROJECT, 2021
## B-MUL-200-STG-2-1-mydefender-timothe.coniel
## File description:
## Makefile
##

SRC		=		Source/main.c 					\
				Source/Rigor/start_errors.c 	\
				Source/Start/initialize_wnd.c 	\

NAME	=		my_defender

all:	$(NAME)

$(NAME):		$(SRC)
		gcc -o $(NAME) $(SRC) -l csfml-window -l csfml-graphics -l csfml-system -l csfml-audio

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:		fclean all