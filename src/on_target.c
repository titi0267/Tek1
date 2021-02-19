/*
** EPITECH PROJECT, 2021
** on target by Timothy CONIEL
** File description:
** on_target.c
*/

#include "../include/my.h"

int find_target(map_t *map)
{
    int i = 0;
    int p = 0;
    int nbr_o = find_char(map->str, 'O', 0);

    map->target_car = malloc(sizeof(int) * (nbr_o + 1));
    map->target_line = malloc(sizeof(int) * (nbr_o + 1));
    for (; map->line_map[i] != NULL; i++) {
        for (int y = 0; map->line_map[i][y] != '\0'; y++) {
            if (map->line_map[i][y] == 'O') {
                map->target_line[p] = i;
                map->target_car[p] = y;
                p++;
            }
        }
    }
    map->target_car[p] = -1;
    map->target_line[p] = -1;
}

void replace_o(map_t *map)
{
    int i = 0;

    for (; map->target_line[i] != -1 && map->target_car[i] != -1; i++) {
        if (map->line_map[map->target_line[i]][map->target_car[i]] == ' ')
            map->line_map[map->target_line[i]][map->target_car[i]] = 'O';
    }
}

int small_screen(map_t *map, int i, int *str_len)
{
    if ((map->col < (my_strlen(map->line_map[0]) / 2) + (COLS / 2) + 1)
        || (map->row < ((word_tablen(map->line_map) / 2) + (LINES / 2) + 1))) {
        clear();
        mvprintw((LINES / 2), (COLS / 2) - (28 / 2), "Enlarge the screen !");
        refresh();
        map->small_scr = 1;
        switch (getch()) {
            case SPACE:
                map->restart = 1;
                break;
            case KEY_q:
                map->quit = 1;
                break;
        }
        if (map->restart == 1 || map->quit == 1) {
            map->small_scr = 1;
            clear();
        }
        return (0);
    }
    return (1);
}