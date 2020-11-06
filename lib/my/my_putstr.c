/*
** EPITECH PROJECT, 2020
** my_putstr.c by Elliot WALDVOGEL
** File description:
** my_putstr
*/

#include "../../include/stdio.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}