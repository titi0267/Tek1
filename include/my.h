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

void my_putchar(char c);
int my_putstr(char const *str);
int my_strncmp(char *cmp, char *cmpd);
int my_putnbr(int nb);
int my_getnbr(char *str);
char *my_int_str(int nb, lib_t *lib);
int my_printf(char *str, ...);

int read_map(map_t *map, char *filepath);
int find_player(map_t *map);
int find_target(map_t *map);
void key_pressed(map_t *map);
void replace_o(map_t *map);
int win_mode(map_t *map);

#endif /* !MY_H_ */
