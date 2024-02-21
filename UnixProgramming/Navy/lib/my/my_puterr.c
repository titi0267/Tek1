/*
** EPITECH PROJECT, 2020
** my_puterr.c by Elliot WALDVOGEL
** File description:
** my_puterr
*/

#include "../../include/my.h"

void my_puterr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putcerr(str[i]);
    }
}