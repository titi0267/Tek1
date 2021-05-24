/*
** EPITECH PROJECT, 2020
** my_char_compare by Timothy CONIEL
** File description:
** my_strncmp.c
*/
#include "my.h"

int my_strncmp(char *cmp, char *cmpd)
{
    int p = 0;

    while (cmp[p] != '\0') {
        if (cmpd[p] == cmp[p])
            p++;
        else
            return (-1);
    }
    return (0);
}