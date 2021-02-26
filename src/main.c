/*
** EPITECH PROJECT, 2021
** main by Timothy CONIEL
** File description:
** main.c
*/

#include "../include/my.h"

int big_loop(map_t *map, char **av)
{
    int *str_len = line_len(map->str);
    int x;

    while (1) {
        x = in_big_loop(map, str_len);
        if (x == 1)
            return (1);
        if (x == 0)
            return (0);
        if (map->quit == 1)
            break;
        else if (map->restart == 1)
            break;
    }
    if (map->restart == 1)
        restart_gm(map, av);
    return (0);
}

int init_ncurses(map_t *map, char **av)
{
    int x;
    map->quit = 0;

    if (read_map(map, av[1]) != 0)
        return (ERROR);
    map->line_map = str_to_wordarray(map->str);
    if (assemble_error(map) == ERROR)
        return (ERROR);
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    find_target(map);
    x = big_loop(map, av);
    endwin();
    if (x == 0)
        return (0);
    if (x == 1)
        return (1);
    return (-1);
}

int main(int ac, char **av)
{
    map_t *map;
    int x;

    if ((map = malloc(sizeof(map_t))) == NULL)
        return (ERROR);
    if (error_handling(ac, av) == ERROR)
        return (ERROR);
    x = init_ncurses(map, av);
    if (x == ERROR)
        return (ERROR);
    else if (x == 0)
        return (0);
    else
        return (1);
    return (0);
}
