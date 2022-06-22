/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** my_strcat.c
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