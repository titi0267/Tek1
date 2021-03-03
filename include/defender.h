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

void resize_wnd_med(window_t *wnd);
void medscr_button(settings_t *stg);
void hover_medscr_button(settings_t *stg);
void hover_medscr(settings_t *stg, window_t *wnd);
void click_resize_med(settings_t *stg, window_t *wnd, sfEvent event);

void resize_wnd_full(window_t *wnd);
void hover_fullscr_button(settings_t *stg);
void fullscr_button(settings_t *stg);
void hover_fullscr(settings_t *spt, window_t *wnd);
void click_resize_full(settings_t *stg, window_t *wnd, sfEvent event);

float box_size_y(window_t *wnd, float y);
float box_size_x(window_t *wnd, float x);

void volume_spt(volume_t *vol);
void vol_nbr_spt(volume_t *vol);
void volume_up_spt(volume_t *vol);
void volume_down_spt(volume_t *vol);
void click_down_vol(volume_t *vol, window_t *wnd);
void click_up_vol(volume_t *vol, window_t *wnd);

void create_sprite_arr(menu_t *menu);
void return_to_one(menu_t *menu);
void return_to_one(menu_t *menu);
void fill_list(menu_t **menu, window_t *wnd);

void backgd_menu(menu_t *menu);

void settings_spt(menu_t *menu, window_t *wnd);
void setting_button(menu_t *menu, window_t *wnd);
void button_setting(button_t *button, menu_t *menu);
void hover_setting_but(button_t *button);
void hover_setting(button_t *button, window_t *wnd);
void setting_bg(menu_t *menu, window_t *wnd);
void click_settings(menu_t *menu, sfEvent event, window_t *wnd);
void draw_spt_setting(menu_t *menu, window_t *wnd);

void hover_back_to_menu_spt(settings_t *stg);
void back_to_menu_spt(menu_t *menu);
void hover_return(settings_t *stg, window_t *wnd);
void switch_bg(menu_t *menu, window_t *wnd);
void return_bg_next(menu_t *menu, sfVector2f global_pos);
void return_side_setting(menu_t *menu, sfVector2f global_pos);
void return_to_menu(menu_t *menu, settings_t *stg, sfEvent event, window_t *wnd);

void hover_play_but(button_t *button);
void hover_play(button_t *button, window_t *wnd);
void button_play(button_t *button);

void button_leave(menu_t *menu, button_t *button);
void hover_leave(button_t *button, window_t *wnd);
void hover_leave_but(button_t *button);
void leave_gm(menu_t *menu, button_t *button, sfEvent event, window_t *wnd);

void game_name(menu_t *menu);
void main_menu_draw(menu_t *menu, window_t *wnd);

void destroy1(core_t *core);


#endif /* !DEFENDER_H_ */
