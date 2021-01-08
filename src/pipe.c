/*
** EPITECH PROJECT, 2020
** Collision by Timothy CONIEL
** File description:
** collision.c
*/
#include "../include/my.h"

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

int pipe_sprite(enemy_t *enemy, map_t *buff, player_t *bird)
{
    enemy->pipe_tex = sfTexture_createFromFile("png/pipe.png", NULL);
    enemy->pipe_tex_d = sfTexture_createFromFile("png/pipe_down.png", NULL);
    enemy->pipe_tex_u = sfTexture_createFromFile("png/pipe_up.png", NULL);
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