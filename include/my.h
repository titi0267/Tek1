/*
** EPITECH PROJECT, 2020
** my_functions by Timothy CONIEL
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_
#include "../lib/my/printf/myp.h"
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
int my_printf(char *, ...);

int print_map(map_t *buff);
int wich_map(int ac, char **av, map_t *buff);

void init_background(background_t *back);
void background(background_t *back);
void background_update(sfRenderWindow *window, background_t *back);

void init_bottom(background_t *back);
void bottom(background_t *back);
void bottom_update(sfRenderWindow *window, background_t *back);

void bird_init(player_t *bird);
void bird_sprite(player_t *bird);
void birdrect_speed(float delta_time, player_t *bird);
void bird_update(player_t *bird, sfRenderWindow *window);
void fall(player_t *bird, float delta_time);
void jump(player_t *bird);

void init_pipe(enemy_t *enemy, map_t *buff, player_t *bird);
void pipe_sprite(enemy_t *enemy, map_t *buff, player_t *bird);
void pipe_update(sfRenderWindow *window, enemy_t *enemy);

void limit(enemy_t *enemy, player_t *bird);
void collision(player_t *bird);
void bird_pass(gather_t *gather);
void score(score_t *score);
void noise(sound_t *sound);

void keep_window_open(map_t *buff);
void poll_event(sfRenderWindow *window, player_t *bird);
void updater(sfRenderWindow *window, gather_t *gather);
void destroy_sprite(gather_t *gather, sfRenderWindow *window);

#endif /* !MY_H_ */
