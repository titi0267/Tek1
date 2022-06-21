/*
** EPITECH PROJECT, 2021
** init obstacle next by Timothy CONIEL
** File description:
** init_obstacle_next.c
*/
#include "../../include/my.h"

int init_pipe(enemy_t *enemy, map_t *buff, player_t *bird)
{
    int x = malloc_array(enemy, buff, bird);

    if (x == -1) {
        my_printf("Error, Malloc didn't worked as expected\n");
        return (-1);
    }
    for (; buff->lin_val != 11; buff->lin_val++) {
        for (; buff->line[buff->lin_val][buff->char_val] != '\0';
            buff->char_val++) {
            space_btw_pipe(enemy, buff);
            if (buff->line[buff->lin_val][buff->char_val] ==
                ' ' && (buff->char_val % 8) == 0)
                fill_array(enemy, bird);
            place_obstacles(enemy, buff);
            place_obstacles_next(enemy, buff);
        }
        buff->char_val = 0;
    }
    return (0);
}
