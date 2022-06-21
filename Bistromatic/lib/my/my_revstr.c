/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** my_revstr.c
*/

#include "include/my.h"

char *my_revstr(char *str)
{
    char origin[my_strlen(str)];
    int j = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        origin[i] = str[i];
    }
    for (int i = (my_strlen(str) - 1); i >= 0; i--) {
        str[j++] = origin[i];
    }
    str[j] = '\0';
    return (str);
}