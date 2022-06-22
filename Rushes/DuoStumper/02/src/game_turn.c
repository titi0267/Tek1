/*
** EPITECH PROJECT, 2021
** game turns
** File description:
** game_turn.c
*/

#include "../include/my.h"

int turn_nbr(char **av, duo_stp_t *map)
{
    int u = 0;
    map->temp_two = malloc(sizeof(char *) * (map->line_nbr + 1));
    map->turns = my_getnbr(av[2]);
    for (int e = 0; map->line[e] != NULL; e++) {
        map->temp_two[e] = malloc(sizeof(char) * (map->char_nbr + 1));
        for (int u = 0; map->line[e][u] != '\0'; u++)
            map->temp_two[e][u] = map->line[e][u];
        map->temp_two[e][u] = '\0';
        u = 0;
    }
    for (int i = 0; i != map->turns; i++) {
        find_map(map);
   }
    for (int x = 0; map->temp_two[x] != NULL; x++)
        my_putstr(map->temp_two[x]);
} 

int find_map(duo_stp_t *map)
{
    int x = 0;

    for (int i = 0; map->line[i] != NULL; i++) {
        for (int f = 0; map->line[i][f] != '\n'; f++) {
            x = over_cell(map, i, f);
            x += under_cell(map, i, f);
            x += side_cell(map, i, f);
            change_map(map, x, i, f);
        }
    }
}

void change_map(duo_stp_t *map, int x, int i, int f)
{
    if (x == 3)
        map->temp_two[i][f] = 'X';
    if (x == 1 || x == 0)
        map->temp_two[i][f] = '.';
    if (x > 3)
        map->temp_two[i][f] = '.';
            
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

    if (i != (map->line_nbr - 1) && f != 0 && f != map->char_nbr) {
        if (map->line[i + 1][f] == 'X')
            x++;
        if(map->line[i + 1][f + 1] == 'X')
           x++;
        if (map->line[i + 1][f - 1] == 'X')
            x++;
    } else if (i != (map->line_nbr - 1) && f == 0) {
        if (map->line[i + 1][f] == 'X')
            x++;
        if (map->line[i + 1][f + 1] == 'X')
            x++;
    } else if (i != (map->line_nbr - 1) && f == map->char_nbr) {
        if (map->line[i + 1][f] == 'X')
            x++;
        if (map->line[i + 1][f - 1] == 'X')
            x++;
    }
    return (x);
}
