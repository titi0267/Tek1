/*
** EPITECH PROJECT, 2020
** Cpool day 4
** File description:
** gfs
*/

#include "include/my.h"

int my_putstr(char const *str)
{
    for (int k = 0; str[k] != '\0'; k++) {
        my_putchar(str[k]);
    }
}
