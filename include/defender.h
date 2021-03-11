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
void print_scene(menu_t *menu, window_t *wnd, game_t *game);

void resize_wnd_med(menu_t *menu, window_t *wnd);
void medscr_button(settings_t *stg);
void hover_medscr_button(settings_t *stg);
void click_medscr_button(settings_t *stg);
void print_medscr(settings_t *stg, window_t *wnd, menu_t *menu);
void click_resize_med(settings_t *stg, window_t *wnd, sfEvent event);

void resize_wnd_full(window_t *wnd);
void hover_fullscr_button(settings_t *stg);
void fullscr_button(settings_t *stg);
void click_fullscr_button(settings_t *stg);
void print_fullscr(settings_t *spt, window_t *wnd, menu_t *menu);
void click_resize_full(settings_t *stg, window_t *wnd, sfEvent event);

float box_size_y(window_t *wnd, float y);
float box_size_x(window_t *wnd, float x);

void volume_spt(volume_t *vol);
void vol_nbr_spt(volume_t *vol);
void volume_up_spt(volume_t *vol);
void volume_down_spt(volume_t *vol);
void click_down_vol(volume_t *vol, window_t *wnd);
void click_up_vol(volume_t *vol, window_t *wnd);
void up_click_spt(volume_t *vol);
void down_click_spt(volume_t *vol);
void hover_up_spt(volume_t *vol);
void hover_down_spt(volume_t *vol);
void print_up_vol(menu_t *menu, window_t *wnd);
void print_down_vol(menu_t *menu, window_t *wnd);
void change_vol_down(menu_t *menu);
void change_vol_up(menu_t *menu);

void mv_stg_one(menu_t *menu, sfVector2f pos);
void mv_stg_two(menu_t *menu, sfVector2f pos);
void mv_stg_three(menu_t *menu, sfVector2f pos);
void mv_stg_four(menu_t *menu, sfVector2f pos);
void mv_to_stg_all(menu_t *menu);

void mv_menu_one(menu_t *menu, sfVector2f pos);
void mv_menu_two(menu_t *menu, sfVector2f pos);
void mv_menu_three(menu_t *menu, sfVector2f pos);
void mv_menu_four(menu_t *menu, sfVector2f pos);
void mv_menu_all(menu_t *menu);

void return_to_one(menu_t *menu);
void return_to_one(menu_t *menu);
void fill_list(menu_t **menu, window_t *wnd);

void backgd_menu(menu_t *menu);

void settings_spt(menu_t *menu, window_t *wnd);
void setting_button(menu_t *menu, window_t *wnd);
void button_setting(button_t *button, menu_t *menu);
void hover_setting_but(button_t *button);
void draw_setting(menu_t *menu, window_t *wnd);
void click_setting_but(button_t *button);
void setting_bg(menu_t *menu, window_t *wnd);
void mv_to_menu(menu_t *menu);
void mv_to_stg(menu_t *menu);

void hover_back_to_menu_spt(settings_t *stg);
void back_to_menu_spt(menu_t *menu);
void draw_return(settings_t *stg, menu_t *menu, window_t *wnd);
void switch_bg(menu_t *menu);
void return_bg_next(menu_t *menu, sfVector2f global_pos);
void return_side_setting(menu_t *menu, sfVector2f global_pos);
void click_back_to_menu_spt(settings_t *stg);

void hover_play_but(button_t *button);
void click_play_but(menu_t *menu);
void click_on_play(menu_t *menu, window_t *wnd);
void draw_play(menu_t *menu, window_t *wnd);
void button_play(button_t *button);

void button_leave(menu_t *menu, button_t *button);
void draw_leave(button_t *button, window_t *wnd);
void hover_leave_but(button_t *button);
void click_leave_but(button_t *button);

void game_name(menu_t *menu);

void game_bgd(game_t *game);
void shop_button(shop_t *shop);

int manage_enemy(core_t *core);

void destroy_regroup_spt(menu_t *menu);
void destroy_all(core_t *core);

#endif /* !DEFENDER_H_ */
