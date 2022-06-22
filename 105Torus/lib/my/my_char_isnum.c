/*
** EPITECH PROJECT, 2021
** my_char_isnum by Timothy CONIEL
** File description:
** my_char_isnum.c
*/

#include "my.h"

int my_char_isnum(char c)
{
    if (c == '\0')
        return (1);
    if ((c >= 0 && c < '-') || (c > '-' && c < '0')
        || c > '9')
        return (0);
    return (1);
}