/*
** EPITECH PROJECT, 2021
** main by Timothy CONIEL
** File description:
** main.c
*/

#include "../include/my.h"

void help(void)
{
    my_printf("USAGE\n");
    my_printf("    Without bonus : ./my_sokoban map\n");
    my_printf("    With bonus : ./my_sokoban map 1\n");
    my_printf("DESCRIPTION\n    map  file representing the wharehouse map,");
    my_printf(" containing '#' for walls,\n         'P' for the player, ");
    my_printf("'X' for boxes and 'O' for storage locations.\n");
}

int error_handling(map_t *map, int ac, char **av)
{
    int bonus = 0;

    if (ac == 3 && av[2][0] == '1' && av[2][1] == '\0')
        bonus = 1;
    else if (bonus == 0) {
        if (ac != 2) {
            return (ERROR);
        } else if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
            help();
            return (ERROR);
        }
    }
    return (0);
}

int init_ncurses(map_t *map, char **av)
{
    map->quit = 0;
    int x;

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
}

int big_loop(map_t *map, char **av)
{
    int *str_len = line_len(map->str);
    int x;

    while (1) {
        x = in_big_loop(map, av, str_len);
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
}

int main(int ac, char **av)
{
    map_t *map;
    int x;

    if ((map = malloc(sizeof(map_t))) == NULL)
        return (ERROR);
    if (error_handling(map, ac, av) == ERROR)
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
