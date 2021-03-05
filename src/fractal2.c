/*
** EPITECH PROJECT, 2021
** duo stumper
** File description:
** fractal2.c
*/

#include "../include/my.h"

int parse_str_sec(char **av)
{
    for (int i = 0; av[2][i] != '\0'; i++) {
        if (av[2][i] == '@')
            my_putchar('\n');
        else
            my_putchar(av[2[i]);
    }
}
