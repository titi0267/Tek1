/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myrunner-timothe.coniel
** File description:
** test
*/
#include "../include/my.h"
#include "../include/my_struct.h"
#include <stdio.h>

int main(int ac, char **av)
{
    int x = 0;
    map_t *buff = malloc(sizeof(map_t));
    if (buff == NULL)
        return (84);
    x = wich_map(ac, av, buff);
    if (x != 0)
        return (84);
    keep_window_open(buff);
    for (int i = 0; i != 11; i++)
        free(buff->line[i]);
    free(buff->line);
    free(buff->buffer);
    free(buff);
}