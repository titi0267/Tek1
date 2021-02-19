/*
** EPITECH PROJECT, 2021
** assemble by Timothy CONIEL
** File description:
** assemble.c
*/

#include "../include/my.h"

int assemble_lose(map_t *map)
{
    if (corner(map) == 1 || right_border(map) == 1 || down_border(map) == 1 || left_border(map) == 1)
        return (1);
    return (0);

}

void in_big_loop(map_t *map, char **av, int *str_len)
{
    int i = 0;
    map->restart = 0;
    map->small_scr = 0;
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
    winning_case(map, av);
    blocked(map, av);
}