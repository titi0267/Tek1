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
    pos_t *where = malloc(sizeof(pos_t));

    help(ac, av);
    //connection(av, info);
    print_pos(where, info);
    map_p1(buff, where);
    print_map(buff, where, info);
    free(where);
    free(buff);
    free(info);
    return (0);
}