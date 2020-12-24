/*
** EPITECH PROJECT, 2020
** my_char_compare by Timothy CONIEL
** File description:
** my_strncmp.c
*/
#include "my.h"

int my_strncmp(char *cmp, char *cmpd)
{
    int l = 0;

    while (cmp[l] != '\0') {
        if (cmpd[l] == cmp[l])
            l++;
        else
            return (-1);
    }
    return (0);
}