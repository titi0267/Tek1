/*
** EPITECH PROJECT, 2020
** my_string_copy by Timothy CONIEL
** File description:
** my_strcpy.c
*/
#include "myp.h"

char *my_strcpyp(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i += 1) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
