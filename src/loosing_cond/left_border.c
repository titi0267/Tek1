/*
** EPITECH PROJECT, 2021
** left border block by Timothy CONIEL
** File description:
** left_border.c
*/

#include "../../include/my.h"

int count_left_next(map_t *map, int m, int i, int u)
{
    int x = 0;

    if (map->line_map[i][u] == 'O')
        x++;
    if (map->line_map[i][map->target_car[m]] == 'X' && map->line_map[i][u] == 'X')
        x++;
    return (x);
}

int count_left(map_t *map)
{
    int x = 0;
    int m = 0;
    int u = 1;
    int back_m = 0;

    for (int i = 0; map->line_map[i] != NULL; i++) {
        while ( map->target_line[m] != i && map->line_map[i + 1] != NULL) {
            if (map->target_line[m] == -1) {
                i++;
                m = back_m - 1;
            }
            m++;
        }
        back_m = m;
        x += count_left_next(map, m, i, u);
    }
    return (x);
}

int left_border(map_t *map)
{
    int g = 0;
    int x = 0;
    int v = 1;

    x = count_left(map);
    for (int k = 0; map->line_map[k] != NULL; k++) {
        if (map->line_map[k][v - 3] == 'X')
        g++;
    }
    if (g <= x)
        return (0);
    return (1);
}