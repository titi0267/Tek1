/*
** EPITECH PROJECT, 2020
** Collision by Timothy CONIEL
** File description:
** collision.c
*/
#include "../include/my.h"

void init_pipe(enemy_t *enemy, map_t *buff, sfRenderWindow *window)
{
    int c = 0;
    int l = 0;
    int x = 0;
    int i = 0;
    int f = 0;
    int down = 0;

    enemy->pos = malloc(sizeof(sfVector2f) * 90);
    enemy->pos_d = malloc(sizeof(sfVector2f) * 17);
    enemy->pos_u = malloc(sizeof(sfVector2f) * 17);
    enemy->enemy_pos.y = 0;
    enemy->enemy_pos.x = 0;
    for (; l != 11; l++) {
        for (; buff->line[l][c] != '\0'; c++) {
            if (buff->line[l][c] == '\n') {
                enemy->enemy_pos.y = 0;
                enemy->enemy_pos.x = 0;
            }
            if (buff->line[l][c] == ' ' && (c % 8) != 0) {
                enemy->enemy_pos.x = enemy->enemy_pos.x + 60;
            }
            if (buff->line[l][c] == ' ' && (c % 8) == 0) {
                enemy->enemy_pos.x = enemy->enemy_pos.x;
            }
            if (buff->line[l][c] == '2') {
                enemy->enemy_pos.x = enemy->enemy_pos.x;
                enemy->enemy_pos.y = (((l - 1) * 84) - 6);
                enemy->pos[x] = enemy->enemy_pos;
                x++;
            }
            if (buff->line[l][c] == '3') {
                enemy->enemy_pos.x = enemy->enemy_pos.x;
                enemy->enemy_pos.y = (((l - 1) * 84) - 6);
                enemy->pos_d[i] = enemy->enemy_pos;
                i++;
            }
            if (buff->line[l][c] == '4') {
                enemy->enemy_pos.x = enemy->enemy_pos.x;
                enemy->enemy_pos.y = (((l - 1) * 84) - 5);
                enemy->pos_u[f] = enemy->enemy_pos;
                f++;
            }
        }
        c = 0;
    }
}

void pos_update(sfRenderWindow *window, enemy_t *enemy)
{
    for (int x = 0; x < 89; x++) {
        enemy->pos[x].x -= 2;
        sfSprite_setPosition(enemy->my_pipe, enemy->pos[x]);
        sfRenderWindow_drawSprite(window, enemy->my_pipe, NULL);
    }
    for (int x = 0; x < 16; x++) {
        enemy->pos_d[x].x -= 2;
        sfSprite_setPosition(enemy->my_pipe_d, enemy->pos_d[x]);
        sfRenderWindow_drawSprite(window, enemy->my_pipe_d, NULL);
    }
    for (int x = 0; x < 16; x++) {
        enemy->pos_u[x].x -= 2;
        sfSprite_setPosition(enemy->my_pipe_u, enemy->pos_u[x]);
        sfRenderWindow_drawSprite(window, enemy->my_pipe_u, NULL);
    }
}

void pipe_sprite(sfRenderWindow *window, enemy_t *enemy, map_t *buff)
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
    init_pipe(enemy, buff, window);
}

void enemy_speed(float delta_time, map_t *buff, player_t *bird, enemy_t *enemy, sfRenderWindow *window)
{
    static float enmy = 0;

    if (enmy >= 0.01f) {

        enmy = 0;
    }
    enmy = delta_time + enmy;
}
