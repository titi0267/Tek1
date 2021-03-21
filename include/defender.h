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

void update_time(core_t *core);
void draw_menu(menu_t *menu, window_t *wnd);
void draw_settings(menu_t *menu, window_t *wnd);
void draw_game(game_t *game, window_t *wnd, core_t *core);
void draw_shop_bis(core_t *core, window_t *wnd);
void draw_shop(core_t *core, window_t *wnd);
void print_scene(menu_t *menu, window_t *wnd, game_t *game, core_t *core);

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
void mv_to_stg_all(menu_t *menu, pause_t *pause);

void mv_menu_one(menu_t *menu, sfVector2f pos);
void mv_menu_two(menu_t *menu, sfVector2f pos);
void mv_menu_three(menu_t *menu, sfVector2f pos);
void mv_menu_four(menu_t *menu, sfVector2f pos);
void mv_menu_all(menu_t *menu, pause_t *pause);
void select_scene(menu_t *menu);

void return_to_one(menu_t *menu);
void return_to_one(menu_t *menu);
void fill_list(menu_t **menu, window_t *wnd);

void backgd_menu(menu_t *menu);

void settings_spt(menu_t *menu, window_t *wnd);
void setting_button(menu_t *menu, window_t *wnd);
void button_setting(button_t *button, menu_t *menu);
void hover_setting_but(button_t *button);
void draw_setting_btn(menu_t *menu, window_t *wnd);
void click_setting_but(button_t *button);
void setting_bg(menu_t *menu, window_t *wnd);
void mv_to_menu(menu_t *menu);
void mv_to_stg(menu_t *menu);
void draw_settings(menu_t *menu, window_t *wnd);

void hover_back_to_menu_spt(settings_t *stg);
void back_to_menu_spt(menu_t *menu);
void draw_return(settings_t *stg, menu_t *menu, window_t *wnd);
void switch_bg(menu_t *menu, pause_t *pause);
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
void shop_button(shop_t *shop, menu_t *menu);
void click_shop(shop_t *shop, window_t *wnd, menu_t *menu);
void get_spt_mouse(tower_t *tower, window_t *wnd);
void tower_array(game_t *game);
void fill_pos_def(game_t *game);
void is_good(game_t *game);
void range_def(game_t *game, enemy_t *enemy, time_t *time);
void fill_alrd_build(game_t *game);
void calc_vector(game_t *game, menu_t *menu);
void create_rect_def(tower_t *tower);

void pause_but(pause_t *pause);
void pause_click(pause_t *pause, window_t *wnd, core_t *core);
void draw_pause(pause_t *pause, window_t *wnd, core_t *core);
void play_again_but(pause_t *pause, menu_t *menu);
void draw_restart(pause_t *pause, menu_t *menu, window_t *wnd);

void ice_tower_spt(tower_t *tower);
void click_ice_tower(window_t *wnd, menu_t *menu, tower_t *tower);
void ice_def(game_t *game);

void archer_spt(tower_t *tower);
void click_arrow_tower(window_t *wnd, menu_t *menu, tower_t *tower);
void archer_def(game_t *game);

void wizzard_spt(tower_t *tower);
void click_wiz_tower(window_t *wnd, menu_t *menu, tower_t *tower);
void wiz_def(game_t *game);

void manage_enemy(core_t *core);
void feed_spt(core_t *core);
int manage_pirat(core_t *core);
void rect_pirat(core_t *core);
int moove_pirat(core_t *core, pirat_data_t *data_bis);
int move_road2(core_t *core, pirat_data_t *data);
int attack(core_t *core, pirat_data_t *data);
int manage_life(core_t *core);
void check_life(core_t *core);
int check_wave(core_t *core);
void moove_rect(core_t *core);
int manage_wave(core_t *core);
int manage_kill(core_t *core);
char *my_itoa(int r, char *result);
char *rev_str(char *str);
int my_strlen(char *str);
void manage_sound_game(core_t *core);
void init_spt_ingame(core_t *core);
void init_spt_ingame(core_t *core);
void init_eco(core_t *core);
void eco_center_spt(tower_t *tower);
void free_linked_list(pirat_data_t *data);
void feed_enemy(core_t *core);
int manage_move(core_t *core, pirat_data_t *data);
void manage_price_all(core_t *core);

void add_def(game_t *game);
void print_def(game_t *game, window_t *wnd);

void destroy_regroup_spt(core_t *core);
void destroy_all(core_t *core);
void destroy_shop_text(shop_t *shop);
void destroy_stg_bg_tex(menu_t *menu);
void destroy_volume_tex(volume_t *volume);
void destroy_size_stg_tex(settings_t *stg);
void destroy_volume_spt(volume_t *vol);
void destroy_size_stg_spt(settings_t *stg);
void destroy_shop_spt(shop_t *shop);
void destroy_enemy_tex(enemy_t *enemy);
void destroy_enemy_spt(enemy_t *enemy);
void destroy_menu_buttons_tex(menu_t *menu);
void destroy_menu_buttons_spt(menu_t *menu);
void destroy_stg_bg_tex(menu_t *menu);
void destroy_stg_bg_spt(menu_t *menu);
void destroy_shop_tex(shop_t *shop);

#endif /* !DEFENDER_H_ */
