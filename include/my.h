/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** 
*/

#ifndef MY_H
#define MY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av);
int error_argnbr(int ac, char **av);
int error_arg_one(int ac, char **av);
int my_putchar(char c);
int my_getnbr(char *str);
int parse_str_sec(char **av);
int parse_str_zero(char **av);

#endif
