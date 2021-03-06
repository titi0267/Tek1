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

int read_map(duo_stp_t *map, char **av);
int store_words(duo_stp_t *duo);
int all_words(duo_stp_t *duo);

int my_getnbr(char *buffer);
void error_argnbr(int ac, char **av);
void arr_to_small(duo_stp_t *duo);
void error_next(int ac, char **av, duo_stp_t *duo);
int error_string_two(int ac, char **av);
int nbr_line(char *buffer);
int nbr_char(char *buffer);
int my_revstr(char *str);

#endif /* !MY_H_ */
