/*
** EPITECH PROJECT, 2021
** error handler by Timothy CONIEL
** File description:
** error_handler.c
*/

#include "../include/my.h"

int assemble_error(map_t *map)
{
    if (target_box(map) == ERROR || is_player(map) == ERROR)
        return (ERROR);
}
/*if ( is_o == 0 &&
            (map->line_map[i][y] == 'X' &&
            (((map->line_map[i][y - 1] == '#' && map->line_map[i + 1][y] == '#') || (map->line_map[i][y - 1] == 'X' && map->line_map[i + 1][y] == 'X'))
            || ((map->line_map[i][y - 1] == '#' && map->line_map[i - 1][y] == '#') || (map->line_map[i][y - 1] == 'X' && map->line_map[i - 1][y] == 'X'))
            || ((map->line_map[i][y + 1] == '#' && map->line_map[i + 1][y] == '#') || (map->line_map[i][y + 1] == 'X' && map->line_map[i + 1][y] == 'X'))
            || ((map->line_map[i][y + 1] == '#' && map->line_map[i - 1][y] == '#') || (map->line_map[i][y + 1] == 'X' && map->line_map[i - 1][y] == 'X')))))
                return (1);
*/