/*
** EPITECH PROJECT, 2021
** main by Timothy CONIEL
** File description:
** main for matchstick project
*/

#include "../include/matchstick.h"

int main(int ac, char **av)
{
    map_t *map = malloc(sizeof(map_t));

    if (map == NULL || error_wrong_arg(ac, av) == ERROR ||
        map_created(map, av) == ERROR) {
        my_puterr("exit 84\n");
        return (ERROR);
    }
    for (int i = 0; map->map[i] != NULL; i++) {
        my_printf("%s", map->map[i]);
    }
    free(map);
    return (0);
}