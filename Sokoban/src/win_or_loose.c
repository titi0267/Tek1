/*
** EPITECH PROJECT, 2021
** win or loose by Timothy CONIEL
** File description:
** win_or_loose.c
*/

#include "../include/my.h"

int winning_case(map_t *map, int *str_len)
{
    int i = 0;

    while (win_mode(map) == 1) {
        refresh();
        map->winner = TRUE;
        for (; map->line_map[i] != NULL; i++) {
            mvprintw((LINES / 2) + i - (word_tablen(map->line_map) / 2),
                        (COLS / 2) - (str_len[i] / 2), map->line_map[i]);
            refresh();
        }
        return (TRUE);
    }
    return (FALSE);
}

int blocked(map_t *map, int *str_len)
{
    int i = 0;

    if (assemble_lose(map) == 1) {
        refresh();
        for (; map->line_map[i] != NULL; i++) {
            mvprintw((LINES / 2) + i - (word_tablen(map->line_map) / 2),
                        (COLS / 2) - (str_len[i] / 2), map->line_map[i]);
            refresh();
        }
        return (TRUE);
    }
    return (FALSE);
}
