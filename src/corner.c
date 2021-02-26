/*
** EPITECH PROJECT, 2021
** corner error by Timothy CONIEL
** File description:
** corner.c
*/

#include "../include/my.h"

int x_block(map_t *map, int i, int y)
{
    if (map->line_map[i][y] == 'X'
        && (((map->line_map[i - 1][y] == '#' || map->line_map[i - 1][y] == 'X')
        && (map->line_map[i][y - 1] == 'X' || map->line_map[i][y - 1] == '#'))
        || ((map->line_map[i + 1][y] == '#' || map->line_map[i + 1][y] == 'X')
        && (map->line_map[i][y - 1] == 'X' || map->line_map[i][y - 1] == '#'))
        || ((map->line_map[i + 1][y] == '#' || map->line_map[i + 1][y] == 'X')
        && (map->line_map[i][y + 1] == 'X' || map->line_map[i][y + 1] == '#'))
        || ((map->line_map[i - 1][y] == '#' || map->line_map[i - 1][y] == 'X')
        && (map->line_map[i][y + 1] == 'X' || map->line_map[i][y + 1] == '#'))))
        return (1);
    return (0);
}

int corner_next(map_t *map)
{
    int x = 0;

    for (int i = 1; map->line_map[i] != NULL; i++) {
        for (int y = 0; map->line_map[i][y]; y++) {
            if (x_block(map, i, y) == 1)
                x++;
        }
    }
    return (x);
}