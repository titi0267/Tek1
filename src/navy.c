/*
** EPITECH PROJECT, 2020
** navy.c by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** navy
*/

#include "../include/my.h"
#include "../include/my_struct.h"
#include <stdlib.h>
#include <stdio.h>

void help(int ac, char **av)
{
    if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h')) {
        my_printf("USAGE\n      ./navy [first_player_pid] navy_positions\n");
        my_printf("DESCRIPTION\n      first_player_pid: only for the 2nd ");
        my_printf("player. pid of the first player.\n      navy_positions: ");
        my_printf("file representing the positions of the ships.\n");
    }
}

int main(int ac, char **av)
{
    infin_number_t *info = malloc(sizeof(infin_number_t));
    map_t *buff = malloc(sizeof(map_t));

    //help(ac, av);
    //connection(ac, av, info);
    read_map(buff, info);
    return (0);
}