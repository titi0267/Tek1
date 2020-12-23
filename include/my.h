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
int my_putnbr(int nb);
int my_getnbr(char *str);
int my_printf(char *, ...);
int print_map(map_t *buff);
void timer(float delta_time, background_t *back);
void set_background(sfRenderWindow *window, background_t *back);
void init_background(background_t *back);
void keep_window_open(void);

#endif /* !MY_H_ */
