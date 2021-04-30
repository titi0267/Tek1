/*
** EPITECH PROJECT, 2021
** lib.c
** File description:
** lib.c
*/

#include <unistd.h>
#include "../include/my.h"

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
