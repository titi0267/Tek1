/*
** EPITECH PROJECT, 2021
** assemble by Timothy CONIEL
** File description:
** assemble.c
*/

#include "../include/my.h"

int assemble_lose(map_t *map)
{
    int x = 0;
    int y = 0;

    for (int i = 0; map->line_map[i] != NULL; i++)
        x += find_char(map->line_map[i], 'X', 0);
    y = corner_next(map);
    if (y == x)
        return (1);
    return (0);

}

void in_big_loop_next(map_t *map, int *str_len)
{
    int i = 0;

    if (small_screen(map) == 1)
        map->small_scr = 0;
    if (map->small_scr == 0) {
        for (; map->line_map[i] != NULL; i++) {
            mvprintw((LINES / 2) + i - (word_tablen(map->line_map) / 2),
                        (COLS / 2) - (str_len[i] / 2), map->line_map[i]);
            refresh();
        }
        find_player(map);
        key_pressed(map);
        replace_o(map);
    }
}

int in_big_loop(map_t *map, int *str_len)
{
    map->restart = 0;
    map->small_scr = 0;
    map->winner = FALSE;
    getmaxyx(stdscr, map->row, map->col);
    in_big_loop_next(map, str_len);
    if (winning_case(map, str_len) == TRUE)
        return (0);
    if (map->winner == FALSE && blocked(map, str_len) == TRUE)
        return (1);
    return (-1);
}
