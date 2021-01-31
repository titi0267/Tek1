/*
** EPITECH PROJECT, 2020
** my_char_compare by Timothy CONIEL
** File description:
** my_strncmp.c
*/
#include "my.h"

int my_strncmp(char *cmp, char *cmpd)
{
    int x = 0;
    int y = my_strlen(cmpd);

    while (x != y) {
        if (cmpd[x] == cmp[x])
            x++;
        else
            return (-1);
    }
    return (0);
}

int my_cmpequal(char *cmp, char *cmpd)
{
    int x = 0;
    int y = my_strlen(cmpd);

    while (x != y) {
        if (cmpd[x] == cmp[x])
            x++;
        else
            return (-1);
    }
    return (x);
}