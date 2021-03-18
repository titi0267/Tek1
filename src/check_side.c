/*
** EPITECH PROJECT, 2021
** check side cells
** File description:
** check_side.c
*/

#include "../include/my.h"

int side_cell(duo_stp_t *map, int i, int f)
{
    int x = 0;

    if (f != 0 && f != map->char_nbr) {
        if (map->line[i][f - 1] == 'X')
            x++;
        if (map->line[i][f + 1] == 'X')
            x++;
    } else if (f == 0) {
        if (map->line[i][f + 1] == 'X')
            x++;
    } else if (f == map->char_nbr) {
        if (map->line[i][f - 1] == 'X')
            x++;
    }
    return (x);
}
