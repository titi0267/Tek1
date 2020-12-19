/*
** EPITECH PROJECT, 2020
** game_core.c for navy by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** game_core
*/
#define _XOPEN_SOURCE 700
#include "../include/my.h"
#include "../include/my_struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

void pos_selection_one(char *pos, infin_number_t *info, char **av, int i)
{
    if (pos[0] >= 'A' && pos[0] <= 'H') {
        info->shot_col[info->round] = pos[0];
    }
    if (pos[1] >= '1' && pos[1] <= '8') {
        info->shot_line[info->round] = pos[0];
    }
    if (pos[0] <= 'A' || pos[0] >= 'H' || pos[1] <= '1' || pos[1] >= '8') {
        my_putstr("wrong position", info);
        converge_one(av, info, i);
    }
}

void converge_one(char **av, infin_number_t *info, int i)
{
    my_putstr("attack: ", info);
    while (av[i] == NULL) {
        pause();
        if (av[i] != NULL) {
            pos_selection_one(av[i], info, av, i);
            i++;
            break;
        }
    }
}

void game_core(char **av, infin_number_t *info)
{
    int i = 2;

    if (info->player_one == 1) {
        converge_one(av, info, i);
        i++;
    }
}