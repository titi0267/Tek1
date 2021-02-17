/*
** EPITECH PROJECT, 2021
** player by Timothy CONIEL
** File description:
** player.c
*/

#include "../include/my.h"

int find_player(map_t *map)
{
    int i = 0;

    for (; map->line_map[i] != NULL; i++) {
        for (int y = 0; map->line_map[i][y] != '\0'; y++) {
            if (map->line_map[i][y] == 'P') {
                map->word = i;
                map->car = y;
            }
        }
    }
}