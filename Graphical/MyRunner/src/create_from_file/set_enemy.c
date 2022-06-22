/*
** EPITECH PROJECT, 2021
** set enemy by Timothy CONIEL
** File description:
** set_enemy.c
*/
#include "../../include/my.h"

int pipe_sprite(enemy_t *enemy, map_t *buff, player_t *bird)
{
    enemy->pipe_tex = sfTexture_createFromFile("ressource/img/pipe.png", NULL);
    enemy->pipe_tex_d = sfTexture_createFromFile("ressource/img/pipe_down.png",
                                                NULL);
    enemy->pipe_tex_u = sfTexture_createFromFile("ressource/img/pipe_up.png",
                                                NULL);
    enemy->my_pipe_d = sfSprite_create();
    enemy->my_pipe = sfSprite_create();
    enemy->my_pipe_u = sfSprite_create();
    sfVector2f scale = {1, 1};

    sfSprite_setTexture(enemy->my_pipe, enemy->pipe_tex, sfFalse);
    sfSprite_setScale(enemy->my_pipe, scale);
    sfSprite_setTexture(enemy->my_pipe_d, enemy->pipe_tex_d, sfFalse);
    sfSprite_setScale(enemy->my_pipe_d, scale);
    sfSprite_setTexture(enemy->my_pipe_u, enemy->pipe_tex_u, sfFalse);
    sfSprite_setScale(enemy->my_pipe_u, scale);
    if (init_pipe(enemy, buff, bird) != 0)
        return (-1);
    return (0);
}