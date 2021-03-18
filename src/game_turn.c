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
    printf("turns = %i\n", map->turns); 
}
