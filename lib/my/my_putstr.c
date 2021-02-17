/*
** EPITECH PROJECT, 2020
** my_put_string by Timothy CONIEL
** File description:
** my_putstr.c
*/

#include "my.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}
