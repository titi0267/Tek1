/*
** EPITECH PROJECT, 2021
** check enemy by Timothy CONIEL
** File description:
** check_enemy.c
*/
#include "../../../include/my.h"

void limit(enemy_t *enemy, player_t *bird)
{
    if (bird->position.y >= enemy->limit) {
        bird->position.y = 700;
        bird->death = 1;
    }
}

void bird_btw_pipe(player_t *bird)
{
    while (bird->col_arr <= 16) {
        if (bird->collision[bird->col_arr].x < (bird->position.x + 60) &&
            bird->collision[bird->col_arr].x > (bird->position.x - 84))
            break;
        bird->col_arr++;
    }
    if (bird->col_arr != 17) {
        if ((bird->collision[bird->col_arr].y + 12) < bird->position.y &&
            bird->collision[bird->col_arr].y + ((84 * 2) - 6)
            > (bird->position.y + 42.7f))
            bird->high = 1;
        else
            bird->high = 0;
    }
    if (bird->col_arr == 17)
        bird->high = 1;
    bird->col_arr = 1;
}
