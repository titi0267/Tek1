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
			init_struct/base_alloc.c		\
			init_struct/alloc_all.c			\
			init_struct/alloc.c				\
			graphics/inits/init_audios.c	\
			graphics/main_menu.c			\
			graphics/options_sound.c		\
			graphics/background.c			\
			graphics/inits/init_main_menu.c	\
			graphics/hitbox_main_menu.c		\
			graphics/start.c				\
			graphics/options_graph.c		\
			graphics/manage_graph.c			\
			graphics/inits/init_btn_menu.c	\
			graphics/inits/init_logo.c		\
			graphics/inits/init_pegi.c		\
			graphics/inits/init_options.c		\
			graphics/inits/init_options_gs.c		\
			graphics/options.c				\

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