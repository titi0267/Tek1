/*
** EPITECH PROJECT, 2021
** print_map by Timothy CONIEL
** File description:
** print the map with the first parameter
*/

#include "../include/matchstick.h"
#include <stdio.h>

int take_line_nbr(char **av)
{
    int line = 0;

    line = my_getnbr(av[1]);
    if (line <= 1) {
        my_puterr(
            "The number of lines must be greater than 1(not included).\n");
        return (ERROR);
    }
    if (line >= 100) {
        my_puterr(
            "The number of lines must be smaller than 100(not included).\n");
        return (ERROR);
    }
    return (0);
}

int malloc_map(char **av, map_t *map)
{
    int line = my_getnbr(av[1]) + 2;
    int car_on_line = 3;

    if (take_line_nbr(av) == 84)
        return (ERROR);
    if ((map->map = malloc(sizeof(char *) * (line + 1))) == NULL)
        return (ERROR);
    for (int i = 2; i <= line; i++)
        car_on_line += 2;
    for (int i = 0; i != line; i++)
        if ((map->map[i] = malloc(sizeof(char) * (car_on_line + 1))) == NULL)
            return (ERROR);
    map->car_nbr = car_on_line - 4;
    map->lines_tot = line;
    map->line_nbr = my_getnbr(av[1]);
    map->match_max = my_getnbr(av[2]);
    return (0);
}

void create_outlines(map_t *map)
{
    int i = 0;

    for (int y = 0; y != map->lines_tot; y++) {
        for (; i != (map->car_nbr); i++) {
            if ((i == 0 || i == map->car_nbr - 1) ||
                (y == 0 || y == map->lines_tot - 1))
                map->map[y][i] = '*';
            else
                map->map[y][i] = ' ';
        }
        map->map[y][i] = '\n';
        i = 0;
    }
}

void place_sticks(map_t *map)
{
    int stick_nbr = 1;
    int y = (map->car_nbr / 2);

    for (int i = 0; i < map->lines_tot - 1; i++) {
        for (int v = 0; v < stick_nbr / 2; v++) {
            map->map[i][y - v] = '|';
            map->map[i][y + v] = '|';
        }
        stick_nbr += 2;
    }
}

int map_created(map_t *map, char **av)
{
    if (malloc_map(av, map) == ERROR)
        return (ERROR);
    create_outlines(map);
    place_sticks(map);
    return (0);
}