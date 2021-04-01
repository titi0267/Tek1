/*
** EPITECH PROJECT, 2020
** B-CPE-200-STG-2-1-dante-timothe.coniel
** File description:
** error.c
*/

#include "../include/my.h"
#include "include/dante.h"

void print_usage(void)
{
    my_printf("USAGE\n./generator x y [perfect]\n\nDESCRIPTION\nx and y are");
    my_printf(" the maze's width and heigth.\nYou can add [perfect] at the ");
    my_printf("end to make a perfect maze, otherwise it will be an ");
    my_printf("imperfect one.\n");
}

int error_handler(int ac, char **av, data_t *data)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        print_usage();
        return (1);
    }
    if (ac != 4 && ac != 4) return (84);
    for (int i = 1; i != 3; i++) {
        for (int y = 0; av[i][y] != '\0'; y++) {
            if (av[i] < '0' || av[i] > '9')
                return (84);
        }
    }
    if (ac == 4 && my_strcmp(av[3], "[perfect]") == 0) data->is_perfect = 1;
    if (ac == 4 && my_strcmp(av[3], "[perfect]") != 0) return (84);
    return (0);
}