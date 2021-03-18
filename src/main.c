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

    read_map(map, av);
    store_map(map);
    return (0);
}
