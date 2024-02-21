/*
** EPITECH PROJECT, 2020
** my_putcerr.c by Elliot WALDVOGEL
** File description:
** my_putcerr
*/

#include <unistd.h>

void my_putcerr(char c)
{
    write(2, &c, 1);
}