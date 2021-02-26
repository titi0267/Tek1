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
				Rigor/malloc.c					\
				Start/initialize_wnd.c 			\
				Start/init_regroup.c			\
				Start/init_time.c				\
				Game_core/wnd_open.c				\
				Game_core/events.c					\
				Game_core/menu/settings/resize_window.c			\
				Game_core/menu/settings/setting_button.c		\
				Game_core/menu/settings/switch_bg.c				\
				Game_core/menu/settings/volume.c				\
				Game_core/menu/settings/resize_button.c			\
				Game_core/menu/settings/switch_return_menu.c	\
				Game_core/menu/main_menu/play_button.c			\
				Game_core/menu/main_menu/menu_spt.c			\
				Game_core/menu/main_menu/leave_button.c		\
				Game_core/menu/main_menu/return_to_menu.c	\
				Game_core/menu/main_menu/draw_spt.c			\
				Game_core/timer.c					\
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