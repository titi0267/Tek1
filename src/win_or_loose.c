/*
** EPITECH PROJECT, 2021
** win or loose by Timothy CONIEL
** File description:
** win_or_loose.c
*/

#include "../include/my.h"

int winning_case(map_t *map, char **av)
{
    while (win_mode(map) == 1) {
        clear();
        mvprintw((LINES / 2), (COLS / 2) - (9 / 2), "You Won !");
        refresh();
        map->winner = TRUE;
        usleep(3000000);
        return (TRUE);
    }
    return (FALSE);
}

int blocked(map_t *map, char **av)
{
    if (assemble_lose(map) == 1) {
        clear();
        mvprintw((LINES / 2), (COLS / 2) - (18 / 2), "You are a loser !");
        refresh();
        usleep(3000000);
        return (TRUE);
    }
    return (FALSE);
}
