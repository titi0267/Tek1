/*
** EPITECH PROJECT, 2020
** my_get_number by Timothy CONIEL
** File description:
** my_getnbr.c
*/

#include "my.h"

int my_getnbr(char *str)
{
    int i = 0;
    int j = 0;
    int n = 1;

    for (; str[i] != '\0' && (str[i] == '+' || str[i] == '-'); i++) {
        if (str[i] == '-')
            n *= -1;
    }
    for (; str[i] != '\0' && str[i] <= '9' && str[i] >= '0'; i++)
        j = j * 10 + str[i] - 48;
    if (n == -1)
        return ((-1) * j);
    else
        return (j);
}