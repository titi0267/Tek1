/*
** EPITECH PROJECT, 2021
** pressed key by Timothy CONIEL
** File description:
** press_key.c
*/

#include "../include/my.h"

void up(map_t *map)
{
    if (map->line_map[map->word - 1][map->car] == ' ') {
        map->line_map[map->word - 1][map->car] = 'P';
        map->line_map[map->word][map->car] = ' ';
    } else if (map->line_map[map->word - 1][map->car] == 'X') {
        if (map->line_map[map->word - 2][map->car] == ' ') {
            map->line_map[map->word - 1][map->car]  = 'P';
            map->line_map[map->word - 2][map->car] = 'X';
            map->line_map[map->word][map->car] = ' ';
        } else if (map->line_map[map->word - 2][map->car] == 'O') {
            map->line_map[map->word - 1][map->car] = 'P';
            map->line_map[map->word - 2][map->car] = 'X';
            map->line_map[map->word][map->car] = ' ';
        }
    } else if (map->line_map[map->word - 1][map->car] == 'O') {
        map->line_map[map->word - 1][map->car] = 'P';
        map->line_map[map->word][map->car] = ' ';
    }
}

void down(map_t *map)
{
    if (map->line_map[map->word + 1][map->car] == ' ') {
        map->line_map[map->word + 1][map->car] = 'P';
        map->line_map[map->word][map->car] = ' ';
    } else if (map->line_map[map->word + 1][map->car] == 'X') {
        if (map->line_map[map->word + 2][map->car] == ' ') {
            map->line_map[map->word + 1][map->car] = 'P';
            map->line_map[map->word + 2][map->car] = 'X';
            map->line_map[map->word][map->car] = ' ';
        } else if (map->line_map[map->word + 2][map->car] == 'O') {
            map->line_map[map->word + 1][map->car] = 'P';
            map->line_map[map->word + 2][map->car] = 'X';
            map->line_map[map->word][map->car] = ' ';
        }
    } else if (map->line_map[map->word + 1][map->car] == 'O') {
        map->line_map[map->word + 1][map->car] = 'P';
        map->line_map[map->word][map->car] = ' ';
    }
}

void left(map_t *map)
{
    if (map->line_map[map->word][map->car - 1] == ' ') {
        map->line_map[map->word][map->car - 1] = 'P';
        map->line_map[map->word][map->car] = ' ';
    } else if (map->line_map[map->word][map->car - 1] == 'X') {
        if (map->line_map[map->word][map->car - 2] == ' ') {
            map->line_map[map->word][map->car - 1] = 'P';
            map->line_map[map->word][map->car - 2] = 'X';
            map->line_map[map->word][map->car] = ' ';
        } else if (map->line_map[map->word][map->car - 2] == 'O') {
            map->line_map[map->word][map->car - 1] = 'P';
            map->line_map[map->word][map->car - 2] = 'X';
            map->line_map[map->word][map->car] = ' ';
        }
    } else if (map->line_map[map->word][map->car -1] == 'O') {
        map->line_map[map->word][map->car - 1] = 'P';
        map->line_map[map->word][map->car] = ' ';
    }
}

void right(map_t *map)
{
    if (map->line_map[map->word][map->car + 1] == ' ') {
        map->line_map[map->word][map->car + 1] = 'P';
        map->line_map[map->word][map->car] = ' ';
    } else if (map->line_map[map->word][map->car + 1] == 'X') {
        if (map->line_map[map->word][map->car + 2] == ' ') {
            map->line_map[map->word][map->car + 1] = 'P';
            map->line_map[map->word][map->car + 2] = 'X';
            map->line_map[map->word][map->car] = ' ';
        } else if (map->line_map[map->word][map->car + 2] == 'O') {
            map->line_map[map->word][map->car + 1] = 'P';
            map->line_map[map->word][map->car + 2] = 'X';
            map->line_map[map->word][map->car] = ' ';
        }
    } else if (map->line_map[map->word][map->car +1] == 'O') {
        map->line_map[map->word][map->car + 1] = 'P';
        map->line_map[map->word][map->car] = ' ';
    }
}

void key_pressed(map_t *map, char **av)
{
    switch (getch()) {
        case KEY_UP:
            up(map);
            break;
        case KEY_DOWN:
            down(map);
            break;
        case KEY_LEFT:
            left(map);
            break;
        case KEY_RIGHT:
            right(map);
            break;
        case SPACE:
            map->restart = 1;
            break;
        case KEY_q:
            map->quit = 1;
            break;
    }
}
