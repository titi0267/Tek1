/*
** EPITECH PROJECT, 2020
** my_functions by Timothy CONIEL
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
int store_map(duo_stp_t *map);
int which_file(duo_stp_t *duo);

#endif /* !MY_H_ */
