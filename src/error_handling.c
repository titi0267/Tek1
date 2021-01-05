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

int check_numbers(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_isnum(str[i]) == 0)
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
    if ((ac != 2 && ac != 9) || check != 0) {
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