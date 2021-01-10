/*
** EPITECH PROJECT, 2020
** my_functions by Timothy CONIEL
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_
#include "../lib/my/printf/myp.h"
#include "../lib/my/my.h"
#include "my_struct.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window/Export.h>
#include <fcntl.h>

void my_putchar(char c);
int my_putstr(char const *str);
int my_strncmp(char *cmp, char *cmpd);
int my_putnbr(int nb);
int my_getnbr(char *str);
char *my_int_str(int nb, lib_t *lib);
int my_printf(char *str, ...);

int print_map(map_t *buff, char *filepath);
int wich_map(int ac, char **av, map_t *buff);

void init_background(background_t *back);
void background(background_t *back);
void background_update(sfRenderWindow *window, background_t *back);

void init_bottom(background_t *back);
void bottom(background_t *back);
void bottom_update(sfRenderWindow *window, background_t *back);

void bird_init(player_t *bird);
void bird_sprite(player_t *bird);
void bird_anim_speed(time_t *time, player_t *bird);
void bird_update(player_t *bird, sfRenderWindow *window);

void fall(player_t *bird, time_t *time);
void jump(player_t *bird);
void bird_action(gather_t *gather);

void limit(enemy_t *enemy, player_t *bird);
void bird_btw_pipe(player_t *bird);
void bird_after_pipe(gather_t *gather);
void death(gather_t *gather);

int init_pipe(enemy_t *enemy, map_t *buff, player_t *bird);
int malloc_array(enemy_t *enemy, map_t *buff, player_t *bird);
void fill_array(enemy_t *enemy, player_t *bird);
void place_obstacles(enemy_t *enemy, map_t *buff);
void place_obstacles_next(enemy_t *enemy, map_t *buff);
void space_btw_pipe(enemy_t *enemy, map_t *buff);
int pipe_sprite(enemy_t *enemy, map_t *buff, player_t *bird);
void pipe_update(sfRenderWindow *window, enemy_t *enemy);
void move_pipe_array(player_t *bird);

void init_score(score_t *score);
void init_score_next(score_t *score);
void increase_score(score_t *score, sfRenderWindow *window);
void reset_score(score_t *score);

void create_sound(sound_t *sound);

void init_text(menu_t *menu);
void create_load(menu_t *menu);
void create_button(menu_t *menu);
void create_button_black(menu_t *menu);
void init_button(menu_t *menu);
void update_black(gather_t *gather);
void start_text(menu_t *menu);
void update_press(gather_t *gather);
void update_start(gather_t *gather);
void update_count(gather_t *gather);

void bird_fall_death(player_t *bird, window_t *windo);
void game_over(menu_t *menu);
void update_gm_over(gather_t *gather);
void restart(gather_t *gather, map_t *buff);
void your_score(score_t *score, sfRenderWindow *window);
void best_score(score_t *score, sfRenderWindow *window);
void re_init(gather_t *gather, map_t *buff);

int call_init(gather_t *gather, map_t *buff);
int keep_window_open(map_t *buff);
void poll_event(sfRenderWindow *window, gather_t *gather);
void update_time(time_t *time);
void updater(gather_t *gather);
void destroy(gather_t *gather);

#endif /* !MY_H_ */
