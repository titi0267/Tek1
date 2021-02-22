/*
** EPITECH PROJECT, 2021
** corner error by Timothy CONIEL
** File description:
** corner.c
*/

#include "../include/my.h"

int x_block(map_t *map, int i, int y)
{
    if ((map->line_map[i][y - 1] == 'X' && map->line_map[i + 1][y] == 'X')
        || (map->line_map[i][y - 1] == 'X' && map->line_map[i - 1][y] == 'X')
        || (map->line_map[i][y + 1] == 'X' && map->line_map[i + 1][y] == 'X')
        || (map->line_map[i][y + 1] == 'X' && map->line_map[i - 1][y] == 'X'))
        return (1);
    return (0);
}

int on_o(map_t *map)
{
    int x = 0;

    for (int p = 0; map->target_car[p] != -1; p++) {
        if (map->line_map[map->target_line[p]][map->target_car[p]] == 'X' &&
        (((map->line_map[map->target_line[p]][map->target_car[p] - 1] == '#' &&
        map->line_map[map->target_line[p] + 1][map->target_car[p]] == '#'))
        || ((map->line_map[map->target_line[p]][map->target_car[p] - 1] == '#'
        && map->line_map[map->target_line[p] - 1][map->target_car[p]] == '#'))
        || ((map->line_map[map->target_line[p]][map->target_car[p] + 1] == '#'
        && map->line_map[map->target_line[p] + 1][map->target_car[p]] == '#'))
        || ((map->line_map[map->target_line[p]][map->target_car[p] + 1] == '#'
        && map->line_map[map->target_line[p] - 1][map->target_car[p]] == '#'))))
            x++;
    }
    return (x);
}

int in_corner(map_t *map, int i, int y)
{
    if ((((map->line_map[i][y - 1] == '#' && map->line_map[i + 1][y] == '#'))
    || ((map->line_map[i][y - 1] == '#' && map->line_map[i - 1][y] == '#'))
    || ((map->line_map[i][y + 1] == '#' && map->line_map[i + 1][y] == '#'))
    || ((map->line_map[i][y + 1] == '#' && map->line_map[i - 1][y] == '#'))))
        return (1);
    return (0);
}

int corner_next(map_t *map)
{
    int x = 0;

    for (int i = 0; map->line_map[i] != NULL; i++) {
        for (int y = 0; map->line_map[i][y]; y++) {
            if (map->line_map[i][y] == 'X' && (in_corner(map, i, y) == 1 ||
            x_block(map, i, y) == 1))
                x++;
        }
    }
    return (x);
}
