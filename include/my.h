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
int my_strlen(char *str);
int my_getnbr(char *str);
char *my_int_str(int nb, lib_t *lib);
int my_printf(char *str, ...);

void print_usage(void);
int error_arg(int ac, char **av);
int which_map(char **av, ant_t *buff);
int select_word(ant_t *buffer);
void compare(ant_t *buffer);
int word_place(ant_t *buffer);
int print_word(ant_t *buffer);
int print_place(ant_t *buffer);
void calc_x(ant_t *buffer);
void diff_wrd(ant_t *buffer);
int letter_freq(ant_t *ant);

int giantman_me(int);
int read_map_next_giant(giant_t *buffer, int);
int read_map_giant(giant_t *buffer, char *filepath);
int count_word_giant(giant_t *buffer);
int store_map_giant(giant_t *buffer);
int wich_map_giant(char **av, giant_t *buffer);
int encoded_error(giant_t *buffer);

#endif /* !MY_H_ */
