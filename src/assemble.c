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
    if (y == x)// || right_border(map) == 1 || down_border(map) == 1 || left_border(map) == 1 || up_border(map) == 1)
        return (1);
    return (0);

}

int in_big_loop(map_t *map, char **av, int *str_len)
{
    int i = 0;
    map->restart = 0;
    map->small_scr = 0;
    map->winner = FALSE;
    clear();
    getmaxyx(stdscr, map->row, map->col);
    if (small_screen(map, i, str_len) == 1)
        map->small_scr = 0;
    clear();
    if (map->small_scr == 0) {
        refresh();
        for (; map->line_map[i] != NULL; i++) {
            mvprintw((LINES / 2) + i - (word_tablen(map->line_map) / 2),
                        (COLS / 2) - (str_len[i] / 2), map->line_map[i]);
        }
        find_player(map);
        refresh();
        key_pressed(map, av);
        replace_o(map);
    }
    if (winning_case(map, av) == TRUE)
        return (0);
    if (map->winner == FALSE && blocked(map, av) == TRUE)
        return (1);
    return (-1);
}