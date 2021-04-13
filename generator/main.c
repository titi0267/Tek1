/*
** EPITECH PROJECT, 2020
** B-CPE-200-STG-2-1-dante-timothe.coniel
** File description:
** main.c
*/

#include "../include/my.h"
#include "include/dante.h"

void print_tab(char **tab)
{
    for (int g = 0; tab[g]; g++)
        my_printf("%s\n", tab[g]);
}

void print_inttab(int **tab)
{
    int boolean = 0;

    for (int x = 0; tab[x]; x++) {
        for (int y = 0; tab[x][y] != -1; y++) {
            if (boolean == 1)
                my_printf(", ");
            else
                boolean = 1;
            my_printf("%d", tab[x][y]);
        }
        boolean = 0;
        my_printf("\n");
    }
}

int maze_init(data_t *data)
{
    data->maze = malloc(sizeof(char *) * (data->maze_heigth + 1));
    for (int x = 0; x < data->maze_heigth; x++) {
        data->maze[x] = malloc(sizeof(char) * (data->maze_width + 1));
        for (int y = 0; y < data->maze_width; y++) {
            if (x % 2 == 0) {
                if (y % 2 != 0)
                    data->maze[x][y] = 'X';
                else
                    data->maze[x][y] = '*';
            } else
                data->maze[x][y] = 'X';
        }
        data->maze[x][data->maze_width] = '\0';
    }
    data->maze[data->maze_heigth] = NULL;
    data->maze[0][0] = '*';
    data->maze[data->maze_heigth - 1][data->maze_width - 1] = '*';
}

void put_maze_in_tab_int(data_t *data)
{
    int rand_nb = 2;

    data->tab = malloc(sizeof(int *) * (data->maze_heigth + 1));
    for (int x = 0; x < data->maze_heigth; x++) {
        data->tab[x] = malloc(sizeof(int) * (data->maze_width + 1));
        for (int y = 0; y < data->maze_width; y++) {
            if (data->maze[x][y] == '*') {
                data->tab[x][y] = rand_nb;
                rand_nb++;
            }
            if (data->maze[x][y] == 'X')
                data->tab[x][y] = 0;
        }
        data->tab[x][data->maze_width] = -1;
    }
    data->tab[data->maze_heigth] = NULL;
}

int check_if_finished(data_t *data)
{
    for (int x = 0; data->tab[x]; x++) {
        for (int y = 0; data->tab[x][y] != -1; y++) {
            if (data->tab[x][y] != 0 && data->tab[x][y] != 1) {
                return (1);
            }
        }
    }
    return (0);
}

void set_mazyness(data_t *data)
{
        int x = rand() % (data->maze_heigth - 1);
        int y = 0;
        int left_cell = 0;
        int right_cell = 0;

        if (x % 2 == 0)
            y = rand() % (((data->maze_width - 1) / 2)) * 2 + 1;
        else
            y = rand() % (((data->maze_width - 1) / 2)) * 2 + 2;
        //data->tab[x][y] = 0;
        my_printf("x : %d, y : %d\nmaze[x][y] = %d\n", x, y, data->tab[x][y]);
        if (data->tab[x - 1][y] != )
    if (data->is_perfect == 0) {
        //make it perfect
    }
}

void put_tab_in_map(data_t *data)
{
    for (int x = 0; data->tab[x]; x++) {
        for (int y = 0; data->tab[x][y]; y++) {
            if (data->tab[x][y] == 0)
                data->maze[x][y] = '*';
            else
                data->maze[x][y] = 'X';
        }
    }
}

int main(int ac, char **av)
{
    data_t *data = malloc(sizeof(data_t));
    int error_status = error_handler(ac, av, data);

    if (error_status == 1) return (0);
    else if (error_status == 0) {
        srand(time(NULL));
        maze_init(data);
        put_maze_in_tab_int(data);
        // while (check_if_finished(data) != 0)
            set_mazyness(data);
        put_tab_in_map(data);
        print_tab(data->maze);
        //print_inttab(data->tab);
        my_freeing(data);
    }
    else return (84);
}