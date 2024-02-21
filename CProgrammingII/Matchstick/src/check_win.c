/*
** EPITECH PROJECT, 2021
** check win by Timothy CONIEL
** File description:
** check if someone won
*/

#include "../include/matchstick.h"

void is_pipe_user(map_t *map, user_t *user)
{
    int count_sticks = 0;

    for (int i = 0; map->map[i] != NULL; i++) {
        for (int y = 0; map->map[i][y] != '\n'; y++) {
            if (map->map[i][y] == '|')
                count_sticks++;
        }
    }
    if (count_sticks != 0)
        user->lose = FALSE;
    else
        user->lose = TRUE;
}

void is_pipe_ai(map_t *map, ai_t *ai)
{
    int count_sticks = 0;

    for (int i = 0; map->map[i] != NULL; i++) {
        for (int y = 0; map->map[i][y] != '\n'; y++) {
            if (map->map[i][y] == '|')
                count_sticks++;
        }
    }
    if (count_sticks != 0)
        ai->lose = FALSE;
    else
        ai->lose = TRUE;
}

int who_lost(core_t *core)
{
    if (core->user->lose == TRUE) {
        my_printf("You lost, too bad...\n");
        free_struct(core);
        return (2);
    } else if (core->ai->lose == TRUE) {
        my_printf("I lost... snif... but I'll get you next time!!\n");
        free_struct(core);
        return (1);
    }
    return (0);
}
