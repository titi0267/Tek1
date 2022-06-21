/*
** EPITECH PROJECT, 2021
** map elements Timothy CONIEL
** File description:
** map_elements.c
*/

#include "../include/my.h"

int is_player(map_t *map)
{
    int player = 0;

    for (int i = 0; map->line_map[i] != NULL; i++) {
        for (int b = 0; map->line_map[i][b]; b++) {
            if (map->line_map[i][b] == 'P')
                player++;
        }
    }
    if (player < 1)
        my_puterr("Can't find the player.\n");
    else if (player > 1)
        my_puterr("Too many players.\n");
    else
        return (1);
    return (ERROR);
}

int target_box(map_t *map)
{
    int box = 0;
    int target = 0;

    for (int i = 0; map->line_map[i] != NULL; i++) {
        for (int b = 0; map->line_map[i][b]; b++) {
            if (map->line_map[i][b] == 'X')
                box++;
            if (map->line_map[i][b] == 'O')
                target++;
        }
    }
    if (box < target)
        my_puterr("Not enough boxes !\n");
    else if (box > target)
        my_puterr("Not enough holes !\n");
    else
        return (1);
    return (ERROR);
}
