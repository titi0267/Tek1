##
## EPITECH PROJECT, 2020
## My_Runner by Timothy CONIEL
## File description:
## Makefile
##
CC		=	gcc	-o

SRC=	src/game_core/main.c		\
		src/game_core/display.c		\
		src/game_core/event.c		\
		src/game_core/map.c			\
		src/create_from_file/set_background.c	\
		src/create_from_file/set_bird.c			\
		src/create_from_file/set_enemy.c		\
		src/create_from_file/set_gm_ovr.c		\
		src/create_from_file/set_score.c		\
		src/create_from_file/set_sound.c		\
		src/create_from_file/text_start.c		\
		src/game_init/game_restart/reset.c	\
		src/game_init/destroy_all.c			\
		src/game_init/init_bird.c			\
		src/game_init/init_game.c			\
		src/game_init/init_obstacle_next.c	\
		src/game_init/init_obstacle.c		\
		src/game_init/init_score.c			\
		src/update_pos/collision/check_enemy.c			\
		src/update_pos/collision/update_score.c			\
		src/update_pos/death/behind_bird_stop.c			\
		src/update_pos/death/bird_death.c				\
		src/update_pos/death/move_button.c				\
		src/update_pos/before_space.c					\
		src/update_pos/bird_actions.c					\
		src/update_pos/bird_animation.c					\
		src/update_pos/main_update_pos.c				\
		src/update_pos/move_background.c				\
		src/update_pos/move_start_text.c				\
		src/update_pos/update_enemy_pos.c

CFLAGS	=	-Wall	-Wextra	-pedantic	--std=c99	-L./lib/my	-lmy	-I./include	-l csfml-audio -l csfml-graphics -l csfml-window -l csfml-system -g

NAME	=	my_runner

all:
	${MAKE} -C lib/my/
	$(CC)	$(NAME)	$(SRC)	$(CFLAGS)

clean:
	make	-C	lib/my/	clean

fclean: clean
	rm	-f	$(NAME)
	make	-C	lib/my	fclean

re:	fclean

.PHONY:	all	clean	fclean	re