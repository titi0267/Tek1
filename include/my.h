/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_
#include "my_struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>

void my_putchar(char c);
int my_putstr(char const *str);
int my_getnbr(char *str);
int my_strlen(char const *str);

int read_map(duo_stp_t *map, char **av);
int open_file(duo_stp_t *duo);
int cp_nbr(duo_stp_t *duo, int y);

int find_arg(char **av);
int store_nbrs(char **av, duo_stp_t *duo);
void free_func(duo_stp_t *duo);
int main(int ac, char **av);

#endif /* !MY_H_ */
