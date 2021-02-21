/*
** EPITECH PROJECT, 2021
** end game by Timothy CONIEL
** File description:
** quit.c
*/

#include "../include/my.h"

int blocked_key(map_t *map)
{
    while (1) {
        switch (getch()) {
            case KEY_q:
                map->quit = 1;
                break;
            case SPACE:
                map->restart = 1;
                break;
        }
        if (map->quit == 1 || map->restart == 1) {
            return (TRUE);
        }
        refresh();
    }
}


int win_key(map_t *map)
{
    while (1) {
        switch (getch()) {
            case KEY_q:
                map->quit = 1;
                break;
            case SPACE:
                map->restart = 1;
                break;
        }
        if (map->quit == 1 || map->restart == 1) {
            map->winner = TRUE;
            return (TRUE);
        }
        refresh();
    }
}