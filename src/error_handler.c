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
