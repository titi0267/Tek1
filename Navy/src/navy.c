/*
** EPITECH PROJECT, 2020
** navy.c by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** navy
*/

#include "../include/my.h"
#include "../include/my_struct.h"
#include <stdlib.h>
#include <stdio.h>
extern int connect;

void help(int ac, char **av)
{
    if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h')) {
        my_printf("USAGE\n      ./navy [first_player_pid] navy_positions\n");
        my_printf("DESCRIPTION\n      first_player_pid: only for the 2nd ");
        my_printf("player. pid of the first player.\n      navy_positions: ");
        my_printf("file representing the positions of the ships.\n");
    }
}

void destroy_p1(pos_t *where, map_t *buff)
{
    free(where->column_start);
    free(where->column_end);
    free(where->line_start);
    free(where->line_end);
    for (int i = 0; i != 10; i++)
        free(buff->line[i]);
    free(buff->line);
}

void common_destroy(pos_t *where, map_t *buff, infin_number_t *info)
{
    free(where->pos_1);
    free(where->pos_2);
    free(buff->buffer);
    for (int i = 0; i != 4; i++) {
        free(where->find_pos1[i]);
        free(where->find_pos2[i]);
    }
    free(where->find_pos1);
    free(where->find_pos2);
    free(where);
    free(buff);
    free(info);
}

void destroy_p2(pos_t *where, map_t *buff)
{
    free(where->column_start2);
    free(where->column_end2);
    free(where->line_start2);
    free(where->line_end2);
    for (int i = 0; i != 10; i++)
        free(buff->line2[i]);
    free(buff->line2);
}

void game_loop1(pos_t *where, map_t *buff, infin_number_t *info)
{
    map_p1(where);
    print_map1(buff, where, info);
    game_core(info, where, buff);
    destroy_p1(where, buff);
}

int main(int ac, char **av)
{
    infin_number_t *info = malloc(sizeof(infin_number_t));
    map_t *buff = malloc(sizeof(map_t));
    pos_t *where = malloc(sizeof(pos_t));

    help(ac, av);
    assemble(av, info);
    connect = 0;
    print_pos(where);
    if (ac == 2 && av[1][3] == '1')
            game_loop1(where, buff, info);
    if (ac == 3 && av[2][3] == '2') {
            map_p2(where);
            print_map2(buff, where, info);
            game_core(info, where, buff);
            destroy_p2(where, buff);
    }
    common_destroy(where, buff, info);
    return (0);
}