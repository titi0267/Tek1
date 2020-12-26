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
#include <fcntl.h>

void my_putchar(char c);
int my_putstr(char const *str);
int my_strncmp(char *cmp, char *cmpd);
int my_putnbr(int nb);
int my_getnbr(char *str);
int my_printf(char *, ...);
int print_map(map_t *buff);
void timer(float delta_time, background_t *back);
void set_background(sfRenderWindow *window, background_t *back);
void init_background(background_t *back);
int wich_map(int ac, char **av, map_t *buff);
void bird_sprite(sfRenderWindow *window, player_t *bird);
void birdrect_speed(float delta_time, player_t *bird);
void bird_init(player_t *bird);
void init_pipe(enemy_t *enemy, map_t *buff, sfRenderWindow *window);
void pipe_sprite(sfRenderWindow *window, enemy_t *enemy, map_t *buff);
void enemy_speed(float delta_time, map_t *buff, player_t *bird, enemy_t *enemy, sfRenderWindow *window);
void map_limit(map_t *buff, player_t *bird, enemy_t *enemy, sfRenderWindow *window);
void keep_window_open(map_t *buff);
void pos_update(sfRenderWindow *window, enemy_t *enemy);

#endif /* !MY_H_ */
