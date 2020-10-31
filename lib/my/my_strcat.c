/*
** EPITECH PROJECT, 2020
** gg
** File description:
** gg
*/

#include "include/my.h"

char *my_strcat(char *dest, char const *src)
{
    char *it = dest;

    it = it + my_strlen(dest);
    while (*src != '\0') {
        *it = *src++;
        it++;
    }
    *it = '\0';
    return (dest);
}