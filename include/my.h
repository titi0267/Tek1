/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** 
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

int error_argnbr(int ac, char **av);
int error_arg_one(char **av);
int error_next(int ac, char **av);
int error_string_two(int ac, char **av);

#endif /* !MY_H_ */
