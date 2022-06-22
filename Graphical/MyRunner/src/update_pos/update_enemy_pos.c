/*
** EPITECH PROJECT, 2021
** update enemy pos by Timothy CONIEL
** File description:
** update_enemy_pos.c
*/
#include "../../include/my.h"

void pipe_update(sfRenderWindow *window, enemy_t *enemy)
{
    for (int x = 0; x < 16; x++) {
        enemy->pos_d[x].x -= 4;
        sfSprite_setPosition(enemy->my_pipe_d, enemy->pos_d[x]);
        sfRenderWindow_drawSprite(window, enemy->my_pipe_d, NULL);
    }
    for (int x = 0; x < 16; x++) {
        enemy->pos_u[x].x -= 4;
        sfSprite_setPosition(enemy->my_pipe_u, enemy->pos_u[x]);
        sfRenderWindow_drawSprite(window, enemy->my_pipe_u, NULL);
    }
    for (int x = 0; x < 89; x++) {
        enemy->pos[x].x -= 4;
        sfSprite_setPosition(enemy->my_pipe, enemy->pos[x]);
        sfRenderWindow_drawSprite(window, enemy->my_pipe, NULL);
    }
}

void move_pipe_array(player_t *bird)
{
    while (bird->move_pipe <= 16) {
        bird->collision[bird->move_pipe].x -= 4;
        bird->move_pipe++;
    }
    bird->move_pipe = 1;
}
