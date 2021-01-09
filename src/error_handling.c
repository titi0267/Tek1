/*
** EPITECH PROJECT, 2021
** error_handling.c for 104intersection project by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** error_handling
*/

#include "../include/my.h"
#include "../include/my_struct.h"
#include <stdlib.h>
#include <stdio.h>
#ifndef M_PI
#    define M_PI 3.1415926535897932
#endif

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

int divide_0(sphere_t *sphere)
{
    if (sphere->a == 0) {
        my_printf("ERROR: Cannot divide by 0, no intersecion points\n");
        return (84);
    }
    return (0);
}

int null(infin_number_t *info)
{
    if (info->xv == 0 && info->yv == 0 && info->zv == 0) {
        my_printf("The vector can't be (0, 0, 0), change your arguments.\n");
        return (84);
    }
    if ((info->opt == 1 || info->opt == 2) && info->p <= 0) {
        my_printf("The radius can't be equal or under 0.\n");
        return (84);
    }
    if (info->opt == 3 && (info->p == tan(M_PI / 2) || info->p <= 0)) {
        my_printf("Invalid angle, change the last argument.\n");
        return (84);
    }
    return (0);
}

int error_handling_next(int ac, char **av)
{
    int check = 0;

    if (ac == 9) {
        for (int i = 1; av[i] != 0; i++)
            check += check_numbers(av[i]);
    }
    if ((ac != 2 && ac != 9) || check != 0 || error_arg1(av) != 0) {
        my_puterr("Invalid argument inputs\nFor help execute: ");
        my_puterr("./104intersection -h\n");
        return (84);
    }
    if (check == 0)
        return (0);
    return (84);
}

int error_handling(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] != '-' || av[1][1] != 'h') {
            my_puterr("Invalid argument inputs\nFor help execute: ");
            my_puterr("./104intersection -h\n");
            return (84);
        }
        if (av[1][0] == '-' && av[1][1] == 'h') {
            help();
            return (84);
        }
    }
    return (error_handling_next(ac, av));
}