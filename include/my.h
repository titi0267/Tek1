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
#include <curses.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#define KEY_q 'q'
#define SPACE ' '
#define ERROR 84

int read_map(map_t *map, char *filepath);
int find_player(map_t *map);
int find_target(map_t *map);
void key_pressed(map_t *map, char **av);
void replace_o(map_t *map);
int win_mode(map_t *map);
int init_ncurses(map_t *map, char **av);
int restart_gm(map_t *map, char **av);
int corner(map_t *map);
int winning_case(map_t *map, char **av);
int blocked(map_t *map, char **av);
int big_loop(map_t *map, char **av);
int in_big_loop(map_t *map, char **av, int *str_len);
int small_screen(map_t *map, int i, int *str_len);
int right_border(map_t *map);
int target_box(map_t *map);
int is_player(map_t *map);
int corner_next(map_t *map);
int assemble_lose(map_t *map);
int assemble_error(map_t *map);
int down_border(map_t *map);
int left_border(map_t *map);
int up_border(map_t *map);
int error_handling(map_t *map, int ac, char **av);
void help(void);

int blocked_key(map_t *map);
int win_key(map_t *map);

#endif /* !MY_H_ */
