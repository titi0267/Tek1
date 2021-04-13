/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** free.c
*/

#include "../include/my.h"
#include "include/dante.h"

void my_freeing(data_t *data)
{
    for (int i = 0; data->maze[i]; i++)
        free(data->maze[i]);
    free(data->maze);
    free(data);
}