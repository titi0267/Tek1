/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** start_errors
*/

#include "../../include/defender.h"

void help(void)
{
    my_printf("USAGE\n");
}

int start_error(int ac, char **av)
{
    if (ac != 1) {
        my_puterr("This program needs one argument only !\n");
        return (ERROR);
    } else if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h')) {
        help();
        return (ERROR);
    }
    return (0);
}