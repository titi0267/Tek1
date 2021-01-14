/*
** EPITECH PROJECT, 2021
** antman.c for antman project by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** antman
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    map_t *buff = malloc(sizeof(map_t));

    if (buff == NULL)
        return (84);
    if (wich_map(ac, av, buff) != 0)
        return (84);
    for (int i = 0; i != 11; i++)
        free(buff->line[i]);
    free(buff->line);
    return (0);
}