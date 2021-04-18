/*
** EPITECH PROJECT, 2020
** B-CPE-200-STG-2-1-dante-timothe.coniel
** File description:
** error.c
*/

#include "../include/my.h"
#include "include/struct.h"

void print_usage(void)
{
    my_printf("USAGE\n./generator x y [perfect]\n\nDESCRIPTION\nx and y are");
    my_printf(" the maze's width and heigth.\nYou can add [perfect] at the ");
    my_printf("end to make a perfect maze, otherwise it will be an ");
    my_printf("imperfect one.\n");
}

int check_numbers(char **av, maze_t *maze)
{
    maze->height = my_getnbr(av[1]);
    maze->width = my_getnbr(av[2]);

    if (maze->width <= 0 || maze->height <= 0) return (84);
    return (0);
}

int error_handler(int ac, char **av, maze_t *maze)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        print_usage();
        return (1);
    }
    if (ac != 4 && ac != 3) return (84);
    for (int i = 1; i < 3; i++) {
        for (int y = 0; av[i][y] != '\0'; y++) {
            if (av[i][y] < '0' || av[i][y] > '9')
                return (84);
        }
    }
    if (check_numbers(av, maze) == 84) return (84);
    maze->is_perfect = 0;
    if (ac == 4) {
        if (my_strcmp(av[3], "[perfect]") == 0)
            maze->is_perfect = 1;
        else
            return (84);
    }
    return (0);
}