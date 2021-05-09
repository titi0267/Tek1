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
			parsing.c						\
			audios.c						\
			destroy.c						\
			free_all.c						\
			init.c							\
			tools/tools.c						\
			tools/tools2.c						\
			tools/tools3.c						\
			tools/tool_vect.c					\
			init_struct/alloc_all.c		\
			init_struct/alloc.c			\
			init_struct/base_alloc.c	\
			init_struct/alloc_game.c	\
			menu/inits/init_audios.c		\
			menu/inits/init_btn_menu.c		\
			menu/inits/init_logo.c			\
			menu/inits/init_main_menu.c		\
			menu/inits/init_new_game.c		\
			menu/inits/init_options.c		\
			menu/inits/init_options_gs.c	\
			menu/inits/init_pegi.c			\
			menu/inits/init_text.c			\
			menu/main_menu/hitbox_main_menu.c		\
			menu/main_menu/main_menu.c				\
			menu/new_game/choose_perso.c				\
			menu/new_game/display_character.c			\
			menu/settings/manage_graph.c		\
			menu/settings/options_graph.c		\
			menu/settings/options_sound.c		\
			menu/settings/options.c				\
			menu/settings/manage_text.c			\
			menu/settings/options_key.c			\
			menu/background.c			\
			menu/start.c				\
			game/shortcuts.c				\
			game/cinematics/cine_start.c			\
			game/cinematics/cine_end.c				\
			game/continue/save_game.c			\
			game/continue/continue.c			\
			game/continue/load_more_value.c			\
			game/continue/lose_game.c			\
			game/continue/sv_statavanc.c		\
			game/menu/exit.c			\
			game/menu/exit_action.c		\
			game/menu/settings_exit.c	\
			game/inits/init_exit.c				\
			game/inits/init_levelup.c				\
			game/inits/init_inventory.c			\
			game/inits/init_player_rect.c		\
			game/inits/init_player_vest.c		\
			game/inits/init_exit_settings.c		\
			game/inits/init_tuto.c				\
			game/inits/init_cinematic1.c		\
			game/inits/init_cinematic2.c		\
			game/inits/init_yellow_man.c		\
			game/inits/init_police_maps.c		\
			game/inits/init_other_maps.c		\
			game/inits/init_audios.c			\
			game/inits/init_phone.c				\
			game/inits/init_stats.c				\
			game/inits/init_lifexp.c			\
			game/inits/init_particle.c			\
			game/inits/init_police_warren.c		\
			game/inits/init_covid.c				\
			game/inits/init_knife.c				\
			game/maps/general_player_mv.c	\
			game/maps/collisions_bis.c		\
			game/maps/switch_map.c			\
			game/maps/directions.c			\
			game/maps/switch_map_police.c	\
			game/maps/collisions.c			\
			game/maps/map_status.c			\
			game/maps/run.c					\
			game/maps/print_warren.c		\
			game/inventory/display_inventory.c		\
			game/inventory/inventory_manager.c		\
			game/inventory/vaccine_manager.c		\
			game/inventory/drop_type.c				\
			game/inventory/reset_inventory.c	\
			game/tutorial/tuto.c		\
			game/tutorial/tuto_map.c	\
			game/avancement/parsing_avance.c			\
			game/avancement/phone.c						\
			game/avancement/game_hitbox.c				\
			game/avancement/game_hitbox_next.c			\
			game/enemies/move_enemy.c				\
			game/enemies/enemy_translate.c			\
			game/enemies/new_enemy.c				\
			game/enemies/collisions_enemy.c			\
			game/enemies/collisions_enemy2.c			\
			game/enemies/enemy_choose_direction.c	\
			game/enemies/enemy_rect.c				\
			game/stats/player_stats.c		\
			game/stats/life.c				\
			game/particle/particle.c				\
			game/particle/particle2.c				\
			game/attack/bullet_init.c			\
			game/attack/draw_bullet.c			\
			game/attack/shoot.c					\
			game/attack/move_bullet.c			\
			game/attack/knife.c					\
			game/attack/touched_enemy.c			\
			game/loot/spawn.c				\
			game/loot/hitbox_loot.c			\
			game/cars/init_car.c				\
			game/cars/init_car2.c				\
			game/cars/car.c						\

SRCS = $(addprefix $(SRCSPATH), $(SRCSFILES))

NAME	=	my_rpg

CFLAGS = -lm	-lcsfml-audio	-lcsfml-graphics	-lcsfml-window	-lcsfml-system	-g	-Wall -Wextra -Werror

all:
	$(CC)	$(NAME)	$(SRCS)	$(CFLAGS)

clean:

fclean: clean
	rm -f $(NAME)

re:	fclean	all

.PHONY:	all	clean	fclean	re