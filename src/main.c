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
    my_printf("            ./my_sokoban map.txt\n");
}

int error_handling(map_t *map, int ac, char **av)
{
    if (ac != 2) {
        help();
        return (84);
    }
    return (0);
}

int center_text(map_t *map, char **av)
{
    int *str_len = line_len(map->str);
    int row;
    int col;
    map->quit = 0;

    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    find_target(map);
    while (1) {
        clear();
        getmaxyx(stdscr, col, row);
        for (int i = 0; map->line_map[i] != NULL; i++) {
            mvprintw((LINES / 2) + i - (word_tablen(map->line_map) / 2),
                        (COLS / 2) - (str_len[i] / 2), map->line_map[i]);
        }
        find_player(map);
        refresh();
        key_pressed(map, av);
        replace_o(map);
        while (win_mode(map) == 1) {
            clear();
            mvprintw((LINES / 2), (COLS / 2) - (9 / 2), "You Won !");
            switch (getch()) {
                case KEY_q:
                    map->quit = 1;
                    break;
                case SPACE:
                    restart_gm(map, av);
                    break;
            }
            if (map->quit == 1)
                break;
            refresh();
        }
        if (map->quit == 1)
            break;
    }
    endwin();
}

int main(int ac, char **av)
{
    map_t *map = malloc(sizeof(map_t));
    int i = 0;

    if (error_handling(map, ac, av) == 84)
        return (84);
    read_map(map, av[1]);
    map->line_map = str_to_wordarray(map->str);
    /*for (; map->line_map[i] != NULL; i++) {
        for (int y = 0; map->line_map[i][y] != '\0'; y++)
            my_printf("%c", map->line_map[i][y]);
    }*/
    center_text(map, av);
    return (0);
}
