##
## EPITECH PROJECT, 2021
## B-MUL-200-STG-2-1-myrpg-timothe.coniel
## File description:
## Makefile
##

CC	=	gcc	-o

SRCSPATH = src/

SRCSFILES=	rpg.c							\
			open_window.c					\
			init_window.c					\
			tools.c							\
			parsing.c						\
			audios.c						\
			init_struct/alloc_all.c		\
			init_struct/alloc.c			\
			init_struct/base_alloc.c	\
			menu/inits/init_audios.c		\
			menu/inits/init_btn_menu.c		\
			menu/inits/init_logo.c			\
			menu/inits/init_main_menu.c		\
			menu/inits/init_new_game.c		\
			menu/inits/init_options.c		\
			menu/inits/init_options_gs.c	\
			menu/inits/init_pegi.c			\
			menu/main_menu/hitbox_main_menu.c		\
			menu/main_menu/main_menu.c				\
			menu/new_game/choose_perso.c		\
			menu/new_game/move_characters.c		\
			menu/settings/manage_graph.c		\
			menu/settings/options_graph.c		\
			menu/settings/options_sound.c		\
			menu/settings/options.c				\
			menu/background.c			\
			menu/start.c				\

SRCS = $(addprefix $(SRCSPATH), $(SRCSFILES))

NAME	=	my_rpg

CFLAGS = -lm	-lcsfml-audio	-lcsfml-graphics	-lcsfml-window	-lcsfml-system	-g

all:
	$(CC)	$(NAME)	$(SRCS)	$(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY:	all	clean	fclean	make	re