/*
** EPITECH PROJECT, 2021
** error args by Timothy CONIEL
** File description:
** error arguments
*/

#include "../include/matchstick.h"

void help(void)
{
    my_printf("USAGE:\n");
    my_printf("      ./matchstick A B\n");
    my_printf("DESCRIPTION:\n");
    my_printf("            A > the number of lines that you want.\n");
    my_printf("            B > the number of sticks that can be\n");
    my_printf("                removed every round.\n");
}

int error_arg_nbr(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        help();
        return (ERROR);
    }
    if (ac != 3) {
        my_puterr(
            "Wrong number of arguments, see './matchstick -h' for help !\n");
        return (ERROR);
    }
    if (ac == 3)
        return (0);
    return (ERROR);
}

int error_wrong_arg(int ac, char **av)
{
    if (error_arg_nbr(ac, av) == ERROR)
        return (ERROR);
    for (int i = 0; av[1][i] != '\0'; i++) {
        if (av[1][i] < 48 || av[1][i] > 57) {
            my_puterr("Argument one and two must be numbers !\n");
            return (ERROR);
        }
    }
    for (int i = 0; av[2][i] != '\0'; i++) {
        if (av[2][i] < 48 || av[2][i] > 57) {
            my_puterr("Argument one and two must be numbers !\n");
            return (ERROR);
        }
    }
    return (0);
}