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
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>


void my_putchar(char c);
int my_putstr(char const *str);
int my_strncmp(char *cmp, char *cmpd);
int my_putnbr(int nb);
int my_getnbr(char *str);
char *my_int_str(int nb, lib_t *lib);
int my_printf(char *str, ...);

void print_usage(void);
int wich_map(int ac, char **av, map_t *buff);
int select_word(map_t *buffer);
void compare(map_t *buffer);
int word_place(map_t *buffer);
int print_word(map_t *buffer);
int print_place(map_t *buffer);
void calc_x(map_t *buffer);
void diff_wrd(map_t *buffer);

int giantman_me(int);

#endif /* !MY_H_ */
