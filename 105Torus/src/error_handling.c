/*
** EPITECH PROJECT, 2021
** error_handling by Timothy CONIEL & Sylvian BURN
** File description:
** error_handling.c
*/

#include "../include/my.h"

int check_numbers(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_isnum(str[i]) == 0)
            return (84);
    }
    return (0);
}

int error_arg1(char **av)
{
    if (av[1][0] == '1' || av[1][0] == '2' || av[1][0] == '3')
        return (0);
    return (84);
}

int error_handling_next(int ac, char **av)
{
    int check = 0;

    if (ac == 8) {
        for (int i = 1; av[i] != 0; i++)
            check += check_numbers(av[i]);
    }
    if ((ac != 2 && ac != 8) || check != 0 || error_arg1(av) != 0) {
        my_printf("Invalid argument inputs\nFor help execute: ");
        my_printf("./105torus -h\n");
        return (84);
    }
    if (check == 0)
        return (0);
    return (84);
}

void print_usage(void)
{
    my_printf("USAGE\n");
    my_printf("    ./105torus opt a0 a1 a2 a3 a4 n\n\n");
    my_printf("DESCRIPTION\n    opt        method option:\n");
    my_printf("                  1 for the bisection method\n");
    my_printf("                  2 for Netwton's method\n");
    my_printf("                  3 for the secant method\n");
    my_printf("    a[0-4]    coefficients of the equation\n");
    my_printf("    n         presicion (the application of the polynomial to\n");
    my_printf("              the solution should be smaller than 10^-n\n");
}

int error_handling(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] != '-' || av[1][1] != 'h') {
            my_printf("Invalid argument inputs\nFor help execute: ");
            my_printf("./105torus -h\n");
            return (84);
        }
        if (av[1][0] == '-' && av[1][1] == 'h') {
            print_usage();
            return (84);
        }
    }
    return (error_handling_next(ac, av));
}
