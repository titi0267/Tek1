/*
** EPITECH PROJECT, 2021
** reverse string by Timothy CONIEL
** File description:
** my_revstr.c
*/
#include "my.h"

char *my_revstr(char *str, lib_t *lib)
{
    char temp;
    int i = 0;
    int j = lib->count - 1;

    while (i <= j) {
    if (str[i] == '-') {
        str[i] = '-';
        i++;
    }
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return (str);
}