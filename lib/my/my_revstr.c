/*
** EPITECH PROJECT, 2020
** gg
** File description:
** ggg
*/

#include "include/my.h"


char *my_revstr(char *str)
{
    char origin[my_strlen(str)];
    int j = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        origin[i] = str[i];
    }

    for (int i = (my_strlen(str) - 1); i >= 0; i--) {
        str[j++] = origin[i];
    }
    str[j] = '\0';
    return (str);
}