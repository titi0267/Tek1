/*
** EPITECH PROJECT, 2021
** game turns
** File description:
** game_turn.c
*/

#include "../include/my.h"

int turn_nbr(char **av, duo_stp_t *map)
{
    map->turns = my_getnbr(av[2]);
    for (int i = 0; i != map->turns; i++) {
        find_map(map);
    }
    printf("turns = %i\n", map->turns); 
}

int find_map(duo_stp_t *map)
{
    int x = 0;

    for (int i = 0; map->line[i] != NULL; i++) {
        for (int f = 0; map->line[i][f] != '\n'; f++) {
            x = over_cell(map, i, f);
            x += under_cell(map, i, f);
            x += side_cell(map, i, f);
            printf("x = %i\n", x);
        }
    }
}

int over_cell(duo_stp_t *map, int i, int f)
{
    int x = 0;

    if (i != 0 && f != 0 && f != map->char_nbr) {
        if (map->line[i - 1][f] == 'X')
            x++;
        if (map->line[i - 1][f - 1] == 'X')
            x++;
        if (map->line[i - 1][f + 1] == 'X')
            x++;
    } else if (i != 0 && f == 0) {
        if (map->line[i - 1][f] == 'X')
            x++;
        if (map->line[i - 1][f + 1] == 'X')
            x++;
    } else if (i != 0 && f == map->char_nbr) {
        if (map->line[i - 1][f] == 'X')
            x++;
        if (map->line[i - 1][f - 1] == 'X')
            x++;
    }
    return (x);
}

int under_cell(duo_stp_t *map, int i, int f)
{
    int x = 0;

    if (i != map->line_nbr && f != 0 && f != map->char_nbr) {
        if (map->line[i + 1][f] == 'X')
            x++;
        if(map->line[i + 1][f + 1] == 'X')
           x++;
        if (map->line[i + 1][f - 1] == 'X')
            x++;
    } else if (i != map->line_nbr && f == 0) {
        if (map->line[i + 1][f] == 'X')
            x++;
        if (map->line[i + 1][f + 1] == 'X')
            x++;
    } else if (i != map->line_nbr && f == map->char_nbr) {
        if (map->line[i + 1][f] == 'X')
            x++;
        if (map->line[i + 1][f - 1] == 'X')
            x++;
    }
    return (x);
}
