/*
** EPITECH PROJECT, 2020
** My Runner by Timothy CONIEL
** File description:
** main.c
*/
#include "../include/my.h"
#include "../include/my_struct.h"

int main(int ac, char **av)
{
    map_t *buff = malloc(sizeof(map_t));

    if (buff == NULL)
        return (84);
    if (wich_map(ac, av, buff) != 0)
        return (84);
    if (keep_window_open(buff) != 0)
        return (84);
    for (int i = 0; i != 11; i++)
        free(buff->line[i]);
    free(buff->line);
    free(buff->buffer);
    free(buff);
    return (0);
}