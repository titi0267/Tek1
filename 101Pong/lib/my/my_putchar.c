/*
** EPITECH PROJECT, 2020
** my_putchar.c by Elliot WALDVOGEL
** File description:
** my_putchar
*/

#include "../../include/stdio.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}