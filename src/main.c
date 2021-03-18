/*
** EPITECH PROJECT, 2021
** duo_stumper
** File description:
** duo_stumper.c
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    duo_stp_t *map = malloc(sizeof(duo_stp_t));

    if (error_argnbr(ac, av) == 84)
        return (84);
    if (read_map(map, av) == 84)
        return (84);
    store_map(map);
    return (0);
}
