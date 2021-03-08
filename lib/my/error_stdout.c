/*
** EPITECH PROJECT, 2021
** error stdout 2 by Timothy CONIEL
** File description:
** error_stdout.c
*/

#include "my.h"

void my_putcerr(char c)
{
    write(2, &c, 1);
}

void my_puterr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putcerr(str[i]);
    }
}