/*
** EPITECH PROJECT, 2021
** fractal0.c
** File description:
** 
*/

#include "../include/my.h"

int parse_string_zero(char **av)
{
    for (int i = 0; av[0][i] != '\0'; i++)
        if (av[0][i] == '@')
            my_putchar('\n');
        else
            my_putchar(av[0][i]);
    
}
