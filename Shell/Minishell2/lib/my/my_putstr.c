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

int only_alpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0) {
            if (((str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122)) && str[i] != 95)
                return (-2);
        } else {
            if ((str[i] < 48 || ((str[i] > 58 && str[i] < 65) || (str[i] > 90 && str[i] < 97) || str[i] > 122)) && str[i] != 95)
                return (-1);
        }
    }
    return (0);
}
