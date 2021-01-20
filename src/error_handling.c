/*
** EPITECH PROJECT, 2021
** error_handling by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** error_handling.c
*/

#include "../include/my.h"

int error_arg(int ac, char **av)
{
    if (ac != 3 && ac != 2) {
        my_printf("Wrong amount of arguments, see ./antman -h.\n");
        return (84);
    }
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            print_usage();
            return (84);
        } else {
            my_printf("Wrong arguments, see ./antman -h.\n");
            return (84);
        }
    }
    if (ac == 3 && (av[2][0] != '1' && av[2][0] != '2' && av[2][0] != '3')) {
        my_printf("wrong argument for file type.\n");
        return (84);
    }
    return (0);
}