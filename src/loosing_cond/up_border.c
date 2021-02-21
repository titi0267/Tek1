/*
** EPITECH PROJECT, 2021
** up border block by Timothy CONIEL
** File description:
** up_border.c
*/

#include "../../include/my.h"

int count_up_next(map_t *map, int m, int i, int y)
{
    int x = 0;

    /*clear();
    printw("[%i][%i] = $%c$", i, y, map->line_map[i][y]);
    refresh();
    sleep(1);*/
    if (map->line_map[i][y] == 'O') {
        x++;
    }
    if (map->line_map[i][map->target_car[m]] == 'X' && map->line_map[i][y] == 'X')
        x++;
    if (map->line_map[1][map->target_car[m]] == 'P' && map->line_map[1][y] == 'P')
        x++;
    return (x);
}

int count_up(map_t *map)
{
    int i = 1;
    int m = 0;
    int store_m = 0;
    int x = 0;
    int v = 0;
    int s = 0;
    int is_o = 0;
    int y = 0;

    for (; map->target_line[s] != -1; s++)
        if (map->target_line[s] == 1)
            break;
    if (map->target_line[s] == 1)
        is_o = 1;
    for (;map->line_map[i][y]; y++) {
        if (is_o == 0)
            break;
        while (m != s) {
            if (map->target_car[m] != y && map->line_map[i][y + 1] != '\0') {
                /*clear();
                printw("%i = %i [%i]           v = %i & line = %i", y, map->target_car[m], m, v, map->target_line[v]);
                refresh();
                sleep(3);*/
                if (map->target_car[m] == -1) {
                    y++;
                    m = store_m - 1;
                }
                m++;
            }
        }
        /*clear();
            printw("%i = %i [%i]   %s", y, map->target_car[m], m, map->line_map[i]);
            refresh();
            sleep(3);*/
        store_m = m;
        x += count_up_next(map, m, i, y);
    }
    return (x);
}

int up_border(map_t *map)
{
    int g = 0;
    int x = 0;
    int i = 1;

    x = count_up(map);
    for (int k = 0; map->line_map[i][k] != '\0'; k++) {
        if (map->line_map[i][k] == 'X')
            g++;
    }
    clear();
    printw("X = %i & O = %i", g, x);
    refresh();
    sleep(1);
    if (g <= x)
        return (0);
    return (1);
}
