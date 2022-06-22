/*
** EPITECH PROJECT, 2020
** my_putchar.c by Elliot WALDVOGEL
** File description:
** my_putchar
*/

#include "../../include/my_struct.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}