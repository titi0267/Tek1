/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** my_strncpy.c
*/

#include "./include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    if (my_strlen(src) < n) {
        dest[my_strlen(src)] = '\0';
    }
    return (dest);
}