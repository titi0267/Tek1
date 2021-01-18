/*
** EPITECH PROJECT, 2021
** main by Timothy CONIEL & Sylvian BURN
** File description:
** main.c
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    if (error_handling(ac, av) != 0)
        return (84);

    return (0);
}