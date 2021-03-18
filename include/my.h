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
int my_strncmp(char *cmp, char *cmpd);
int my_putnbr(int nb);
int my_getnbr(char *str);
int read_map(duo_stp_t *map, char **av);
int store_map(duo_stp_t *map);
int nbr_char(char *buffer);
int nbr_line(char *buffer);
int error_argnbr(int ac, char **av);
int error_arg_one(int ac, char **av);

#endif /* !MY_H_ */
