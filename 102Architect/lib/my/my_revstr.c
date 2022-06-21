/*
** EPITECH PROJECT, 2020
** my_revstr.c by Elliot WALDVOGEL
** File description:
** my_revstr
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    char temp;
    int i = 0;
    int j = my_strlen_non_constant(str) - 1;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i = i + 1;
        j = j - 1;
    }
    return (str);
}