/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** defender
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_
#include  "../lib/my/my.h"
#include "struct.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window/Export.h>
#include <fcntl.h>
#include <stddef.h>

int start_error(int ac, char **av);
int struct_alloc(core_t *core);

void initialize_wnd(window_t *wnd);
void wnd_open(core_t *core);
void init_timer(time_t *time);
void init(core_t *core);

void poll_event(window_t *wnd, menu_t *menu);

void update_time(time_t *time);
void resize_wnd(window_t *wnd, menu_t *menu);
float box_size_y(window_t *wnd, float y);
float box_size_x(window_t *wnd, float x);

void setting_button(menu_t *menu, window_t *wnd);
void backgd_menu(menu_t *menu);
void button_setting(button_t *button);
void hover_setting_but(button_t *button);
void hover_setting(button_t *button, window_t *wnd);
void hover_play_but(button_t *button);
void hover_play(button_t *button, window_t *wnd);
void button_play(button_t *button);
void button_leave(menu_t *menu, button_t *button);
void hover_leave(button_t *button, window_t *wnd);
void hover_leave_but(button_t *button);
void leave_gm(menu_t *menu, button_t *button, sfEvent event, window_t *wnd);
void main_menu_draw(menu_t *menu, window_t *wnd);
void game_name(menu_t *menu);

void destroy1(core_t *core);


#endif /* !DEFENDER_H_ */
