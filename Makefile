##
## EPITECH PROJECT, 2021
## B-MUL-200-STG-2-1-mydefender-timothe.coniel
## File description:
## Makefile
##

CC=	gcc	-o

SRCSPATH = Source/

SRCSFILES	=	main.c 			\
				Rigor/start_errors.c 		\
				Rigor/malloc.c				\
				Start/initialize_wnd.c 			 	\
				Start/init_regroup.c			 	\
				Start/init_time.c				 	\
				Start/manage_enemy/manage_enemy.c	\
				Start/manage_enemy/manage_pirat.c	\
				Game_core/wnd_open.c			\
				Game_core/events.c				\
				Game_core/draw_scene.c			\
				Game_core/timer.c				\
				Game_core/menu/settings/resize_window.c			\
				Game_core/menu/settings/setting_button.c		\
				Game_core/menu/settings/switch_bg.c				\
				Game_core/menu/settings/volume.c				\
				Game_core/menu/settings/volume_change.c			\
				Game_core/menu/settings/volume_down_array.c		\
				Game_core/menu/settings/volume_up_array.c		\
				Game_core/menu/settings/full_scr.c				\
				Game_core/menu/settings/medium_scr.c			\
				Game_core/menu/settings/mv_background/mv_to_setting.c		\
				Game_core/menu/settings/mv_background/mv_to_setting_next.c	\
				Game_core/menu/settings/mv_background/mv_to_menu_next.c		\
				Game_core/menu/settings/mv_background/mv_to_menu.c			\
				Game_core/menu/main_menu/play_button.c		\
				Game_core/menu/main_menu/menu_spt.c			\
				Game_core/menu/main_menu/leave_button.c		\
				Game_core/menu/main_menu/return_to_menu.c	\
				Game_core/game/gm_background.c		\
				Game_core/game/shop/shop_button.c	\
				End/destroy.c 			\

SRCS = $(addprefix $(SRCSPATH), $(SRCSFILES))

CFLAGS	=	-Wall	-Wextra	-pedantic	--std=c99	-L./lib/my	-lmy	-I./include	-l csfml-audio -l csfml-graphics -l csfml-window -l csfml-system -g

NAME	=		my_defender

all:
		${MAKE}	-C	lib/my/
	$(CC)	$(NAME)	$(SRCS)	$(CFLAGS)

clean:
		make	-C	lib/my/	clean

fclean:	clean
		rm -f $(NAME)
		make	-C	lib/my	fclean

re:		fclean all

.PHONY:	all	clean	fclean	re