/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** reverse string
*/

#include "my.h"

char *my_revstr(char *str)
{
    int length = my_strlen(str);
    char copy[length];

    for (int i = 0; i < length; i++)
        copy[i] = str[i];
    for (int i = 0; i < length; i++) {
        str[i] = copy[length - 1 - i];
    }
    return (str);
}
