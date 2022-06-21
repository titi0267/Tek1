/*
** EPITECH PROJECT, 2021
** error handler by Timothy CONIEL
** File description:
** error_handler.c
*/

#include "../include/my.h"

int assemble_error(map_t *map)
{
    if (target_box(map) == ERROR || is_player(map) == ERROR ||
        is_hole(map) == ERROR || only_mapcar(map) == ERROR) {
        return (ERROR);
    }
    return (0);
}

int error_handling(int ac, char **av)
{
    if (ac != 2) {
        return (ERROR);
    } else if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        help();
        return (ERROR);
    }
    return (0);
}

void help(void)
{
    my_printf("USAGE\n");
    my_printf("    ./my_sokoban map\n");
    my_printf("DESCRIPTION\n    map  file representing the wharehouse map,");
    my_printf(" containing '#' for walls,\n         'P' for the player, ");
    my_printf("'X' for boxes and 'O' for storage locations.\n");
}

int only_mapcar(map_t *map)
{
    for (int i = 0; map->line_map[i]; i++) {
        for (int x = 0; map->line_map[i][x]; x++) {
            if (map->line_map[i][x] != '#' && map->line_map[i][x] != ' ' &&
                map->line_map[i][x] != 'O' && map->line_map[i][x] != 'X' &&
                map->line_map[i][x] != 'P' && map->line_map[i][x] != '\n' &&
                map->line_map[i][x] != '\0') {
                my_puterr("They are an invalid charactere in the map !\n");
                return (ERROR);
            }
        }
    }
    return (0);
}

int is_hole(map_t *map)
{
    int hole = 0;

    for (int i = 0; map->line_map[i] != NULL; i++) {
        for (int b = 0; map->line_map[i][b]; b++) {
            if (map->line_map[i][b] == 'O')
                hole++;
        }
    }
    if (hole < 1) {
        my_puterr("There is no goal on this map !\n");
        return (ERROR);
    }
    else
        return (1);
}
