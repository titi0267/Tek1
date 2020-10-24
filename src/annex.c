/*
** EPITECH PROJECT, 2020
** annex.c for rush3.c by Elliot WALDVOGEL
** File description:
** annex
*/

#include "../include/my.h"
#include "../include/my_struct.h"

int determine(char *str)
{
    int a = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        a += str[i] - 48;
        if (str [i + 1] != '\0')
            a *= 10;
    }
    return (a);
}