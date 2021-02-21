/*
** EPITECH PROJECT, 2021
** corner error by Timothy CONIEL
** File description:
** corner.c
*/

#include "../../include/my.h"

int x_block(map_t *map, int i, int y)
{
    if ((map->line_map[i][y - 1] == 'X' && map->line_map[i + 1][y] == 'X')
        || (map->line_map[i][y - 1] == 'X' && map->line_map[i - 1][y] == 'X')
        || (map->line_map[i][y + 1] == 'X' && map->line_map[i + 1][y] == 'X')
        || (map->line_map[i][y + 1] == 'X' && map->line_map[i - 1][y] == 'X'))
        return (1);
    return (0);
}

int on_o(map_t *map)
{
    int x = 0;

    for (int p = 0; map->target_car[p] != -1; p++) {
        if (map->line_map[map->target_line[p]][map->target_car[p]] == 'X' &&
        (((map->line_map[map->target_line[p]][map->target_car[p] - 1] == '#' && map->line_map[map->target_line[p] + 1][map->target_car[p]] == '#'))
            || ((map->line_map[map->target_line[p]][map->target_car[p] - 1] == '#' && map->line_map[map->target_line[p] - 1][map->target_car[p]] == '#'))
            || ((map->line_map[map->target_line[p]][map->target_car[p] + 1] == '#' && map->line_map[map->target_line[p] + 1][map->target_car[p]] == '#'))
            || ((map->line_map[map->target_line[p]][map->target_car[p] + 1] == '#' && map->line_map[map->target_line[p] - 1][map->target_car[p]] == '#'))))
            x++;
    }
    return (x);
}

int in_corner(map_t *map, int i, int y)
{
    if ((((map->line_map[i][y - 1] == '#' && map->line_map[i + 1][y] == '#'))
    || ((map->line_map[i][y - 1] == '#' && map->line_map[i - 1][y] == '#'))
    || ((map->line_map[i][y + 1] == '#' && map->line_map[i + 1][y] == '#'))
    || ((map->line_map[i][y + 1] == '#' && map->line_map[i - 1][y] == '#'))))
        return (1);
    return (0);
}

int corner_next(map_t *map)
{
    int x = 0;
    int v = 0;

    for (int i = 0; map->line_map[i] != NULL; i++) {
        for (int y = 0; map->line_map[i][y]; y++) {
            if (map->line_map[i][y] == 'X' && (in_corner(map, i, y) == 1 || x_block(map, i, y) == 1)) {
                x++;
            }

        /*if (map->line_map[i][y] == 'X' &&
        ((map->line_map[i][y - 1] == '#' && map->line_map[i + 1][y] == '#')
        || (map->line_map[i][y - 1] == '#' &&
            map->line_map[i - 1][y] == '#') ||
        (map->line_map[i][y + 1] == '#' && map->line_map[i + 1][y] == '#')
        || (map->line_map[i][y + 1] == '#' &&
            map->line_map[i - 1][y] == '#')))
            x++;
    }*/
        }
    }
    //v = on_o(map);
    ///x = x - v;
    /*clear();
    printw("XBEF = %i", x);
    refresh();
    sleep(1);*/
    //x -= on_o(map);
    /*clear();
    printw("XAF = %i", x);
    refresh();
    sleep(1);*/
    return (x);
}

//(map->line_map[i][y - 1] == 'X' && map->line_map[i + 1][y] == '#')
/*int corner(map_t *map)
{
    int is_o = 0;
    static int i = 0;
    static int y = 0;
    static int p = 0;

    /*for (; map->line_map[i] != NULL; i++) {
        for (; map->line_map[i][y] != '\0'; y++) {
            for (; map->target_car[p] != -1
                && map->target_line[p] != -1; p++) {
                if ((map->target_line[p] == i && map->target_car[p] == y)
                    && map->line_map[i][y] == 'X')
                    is_o = 1;
            }
            if (is_o == 1) {
            clear();
            printw("[%i]", is_o);
            refresh();
            sleep(1);
            }
            if (corner_next(map, is_o, i, y) == 1) {
                return (1);
            }
            p = 0;
        }
        is_o = 0;
        y = 0;
    }
    //i = 0;
    return (0);
}*/
