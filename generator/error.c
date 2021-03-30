/*
** EPITECH PROJECT, 2020
** B-CPE-200-STG-2-1-dante-timothe.coniel
** File description:
** error.c
*/

#include "../include/my.h"

void print_usage(void)
{
    my_printf("USAGE\n./generator x y [perfect]\n\nDESCRIPTION\nx and y are");
    my_printf(" the maze's width and heigth.\nYou can add [perfect] at the ");
    my_printf("end to make a perfect maze, otherwise it will be an ");
    my_printf("imperfect one.\n");
}

int error_handler(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        print_usage();
        return (1);
    }
    if (ac != 4 && ac != 4) return (84);
}