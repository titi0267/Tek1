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

    while (cmp[x] != '\0' || cmpd[x] != '\0') {
        if (cmpd[x] == cmp[x])
            x++;
        else
            return (-1);
    }
    return (0);
}
