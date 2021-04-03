/*
** EPITECH PROJECT, 2020
** B-CPE-200-STG-2-1-dante-timothe.coniel
** File description:
** main.c
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

void print_tab(char **tab)
{
    for (int g = 0; tab[g]; g++)
        my_printf("%s\n", tab[g]);
}

int maze_builder(data_t *data)
{
    data->maze = malloc(sizeof(char *) * (data->maze_heigth + 1));

    for (int i = 0; i <= data->maze_heigth; i++)
        data->maze[i] = malloc(sizeof(char) * (data->maze_width + 2));
    for (int x = 0; x < data->maze_heigth; x++) {
        for (int y = 0; y < data->maze_width; y++)
            data->maze[x][y] = '*';
        data->maze[x][data->maze_width] = '\0';
    }
    data->maze[data->maze_heigth] = NULL;
}

int main(int ac, char **av)
{
    data_t *data = malloc(sizeof(data_t));
    int error_status = error_handler(ac, av, data);

    if (error_status == 1) return (0);
    else if (error_status == 0) {
        maze_builder(data);
        print_tab(data->maze);
        my_freeing(data);
    }
    else return (84);
}