/*
** EPITECH PROJECT, 2021
** restart game by Timothy CONIEL
** File description:
** restart_gm.c
*/

#include "../include/my.h"

int win_mode(map_t *map)
{
    int i = 0;
    int win = 0;

    for (; map->target_line[i] != -1 && map->target_car[i] != -1; i++) {
        if (map->line_map[map->target_line[i]][map->target_car[i]] == 'X')
            win++;
    }
    if (win == find_char(map->str, 'O', 0))
        return (1);
    return (0);
}

int restart_gm(map_t *map, char **av)
{
    read_map(map, av[1]);
    map->line_map = str_to_wordarray(map->str);
    center_text(map, av);
}