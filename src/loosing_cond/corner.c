/*
** EPITECH PROJECT, 2021
** corner error by Timothy CONIEL
** File description:
** corner.c
*/

#include "../../include/my.h"

int corner_next(map_t *map, int is_o, int i, int y)
{
    if (is_o == 0 && map->line_map[i][y] == 'X' &&
    ((map->line_map[i][y - 1] == '#' && map->line_map[i + 1][y] == '#')
    || (map->line_map[i][y - 1] == '#' &&
        map->line_map[i - 1][y] == '#') ||
    (map->line_map[i][y + 1] == '#' && map->line_map[i + 1][y] == '#')
    || (map->line_map[i][y + 1] == '#' &&
        map->line_map[i - 1][y] == '#')))
        return (1);
    return (0);
}

int corner(map_t *map)
{
    int is_o = 0;
    int i = 0;

    for (; map->line_map[i] != NULL; i++) {
        for (int y = 0; map->line_map[i][y] != '\0'; y++) {
            for (int p = 0; map->target_car[p] != -1
                && map->target_line[p] != -1; p++) {
                if ((map->target_line[p] == i && map->target_car[p] == y)
                    && map->line_map[i][y] == 'X')
                    is_o = 1;
            }
            if (corner_next(map, is_o, i, y) == 1)
                return (1);
        }
        is_o = 0;
    }
    return (0);
}
