/*
** EPITECH PROJECT, 2021
** down border block by Timothy CONIEL
** File description:
** down_border.c
*/

#include "../../include/my.h"

int count_down_next(map_t *map, int m, int i, int y)
{
    int x = 0;

    if (map->line_map[i][y] == 'O')
        x++;
    if (map->line_map[i][map->target_car[m]] == 'X' && map->line_map[i][y] == 'X')
        x++;
    return (x);
}

int count_down(map_t *map)
{
    int i = (word_tablen(map->line_map) - 2);
    int m = 0;
    int store_m = 0;
    int x = 0;

    for (int y = 0; map->line_map[i][y]; y++) {
        while ( map->target_car[m] != y && map->line_map[i][y + 1] != '\0') {
            if (map->target_car[m] == -1) {
                y++;
                m = store_m - 1;
            }
            m++;
        }
        store_m = m;
        x += count_down_next(map, m, i, y);
    }
    return (x);
}

int down_border(map_t *map)
{
    int g = 0;
    int x = 0;
    int i = (word_tablen(map->line_map) - 2);

    x = count_down(map);
    for (int k = 0; map->line_map[i][k] != '\0'; k++) {
        if (map->line_map[i][k] == 'X')
        g++;
    }
    if (g <= x)
        return (0);
    return (1);
}