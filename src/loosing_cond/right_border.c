/*
** EPITECH PROJECT, 2021
** right border by Timothy CONIEL
** File description:
** right_border.c
*/

#include "../../include/my.h"

int count_right_next(map_t *map, int m, int i, int u)
{
    int x = 0;

    if (map->line_map[i][u - 3] == 'O')
        x++;
    if (map->line_map[i][map->target_car[m]] == 'X' && map->line_map[i][u - 3] == 'X')
        x++;
    return (x);
}

int count_right(map_t *map)
{
    int x = 0;
    int m = 0;
    int u = 0;
    int back_m = 0;

    for (int i = 0; map->line_map[i] != NULL; i++) {
        u = my_strlen(map->line_map[i]);
        while ( map->target_line[m] != i && map->line_map[i + 1] != NULL) {
            if (map->target_line[m] == -1) {
                i++;
                m = back_m - 1;
            }
            m++;
        }
        back_m = m;
        x += count_right_next(map, m, i, u);
    }
    return (x);
}

int right_border(map_t *map)
{
    int g = 0;
    int x = 0;
    int v = 0;

    x = count_right(map);
    for (int k = 0; map->line_map[k] != NULL; k++) {
        v = my_strlen(map->line_map[k]);
        if (map->line_map[k][v - 3] == 'X')
        g++;
    }
    if (g <= x)
        return (0);
    return (1);
}