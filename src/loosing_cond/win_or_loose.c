/*
** EPITECH PROJECT, 2021
** win or loose by Timothy CONIEL
** File description:
** win_or_loose.c
*/

#include "../../include/my.h"

void winning_case(map_t *map, char **av)
{
    while (win_mode(map) == 1) {
        clear();
        mvprintw((LINES / 2), (COLS / 2) - (9 / 2), "You Won !");
        switch (getch()) {
            case KEY_q:
                map->quit = 1;
                break;
            case SPACE:
                map->restart = 1;
                break;
        }
        if (map->quit == 1 || map->restart == 1)
            break;
        refresh();
    }
    //clear();
}

void blocked(map_t *map, char **av)
{
    while (assemble_lose(map) == 1) {
        clear();
        mvprintw((LINES / 2), (COLS / 2) - (18 / 2), "You are a loser !");
        switch (getch()) {
            case KEY_q:
                map->quit = 1;
                break;
            case SPACE:
                map->restart = 1;
                break;
        }
        if (map->quit == 1 || map->restart == 1)
            break;
        refresh();
    }
}