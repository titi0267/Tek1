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

int read_map(duo_stp_t *map, int i);
int open_file(duo_stp_t *duo);
int store_map(duo_stp_t *map);
int cp_nbr(duo_stp_t *duo, int i);
void print_digit(duo_stp_t *duo);
void print_digit_one(duo_stp_t *duo);
void print_digit_two(duo_stp_t *duo);
void print_digit_three(duo_stp_t *duo);
void print_digit_four(duo_stp_t *duo);
void print_digit_five(duo_stp_t *duo);

int find_arg(char **av);
int store_nbrs(char **av, duo_stp_t *duo);
void free_func(duo_stp_t *duo);
int main(int ac, char **av);

int error_argnbr(int ac, char **av);
int error_arg_one(char **av);
int error_next(int ac, char **av);
int error_string_two(int ac, char **av);

#endif /* !MY_H_ */
