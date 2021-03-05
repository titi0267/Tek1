/*
** EPITECH PROJECT, 2021
** main Duo Stumper
** File description:
** main.c
*/

#include "include/my.h"

int main(int ac, char **av)
{
    if (error_argnbr(ac, av) == 84 || error_arg_one(ac, av) == 84)
        return (84);
    parse_string_zero(av);
    return (0);
}
