/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** my_strdup
*/
#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int i = 0;
    char *str;
    int c = my_strlen(src);

    str = malloc(sizeof(char) * (c + 1));
    while (str[i] < c) {
        str[i] = src[i];
        i += 1;
    }
    str[i] = '\0';
    return (str);
}