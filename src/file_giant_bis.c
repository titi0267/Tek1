/*
** EPITECH PROJECT, 2021
** compress_bis_giant.c for antman project by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** compress_bis_giant
*/

#include "../include/my.h"
#include "../include/my_struct.h"
#include <stdio.h>

void store_map_giant_next(giant_t *buffer, int e, int c, int i)
{
    buffer->line[e][c] = buffer->str[i];
}