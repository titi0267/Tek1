/*
** EPITECH PROJECT, 2021
** behind bird stop by Timothy CONIEL
** File description:
** behind_bird_stop.c
*/
#include "../../../include/my.h"

void pipe_death(sfRenderWindow *window, enemy_t *enemy)
{
    for (int x = 0; x < 16; x++) {
        sfSprite_setPosition(enemy->my_pipe_d, enemy->pos_d[x]);
        sfRenderWindow_drawSprite(window, enemy->my_pipe_d, NULL);
    }
    for (int x = 0; x < 16; x++) {
        sfSprite_setPosition(enemy->my_pipe_u, enemy->pos_u[x]);
        sfRenderWindow_drawSprite(window, enemy->my_pipe_u, NULL);
    }
    for (int x = 0; x < 89; x++) {
        sfSprite_setPosition(enemy->my_pipe, enemy->pos[x]);
        sfRenderWindow_drawSprite(window, enemy->my_pipe, NULL);
    }
}

void back_death(background_t *back, window_t *windo)
{
    sfSprite_setPosition(back->my_background, back->position_back);
    sfRenderWindow_drawSprite(windo->window, back->my_background, NULL);
    sfSprite_setPosition(back->my_background1, back->pos_back);
    sfRenderWindow_drawSprite(windo->window, back->my_background1, NULL);
    sfSprite_setPosition(back->my_bottom1, back->pos_bottom);
    sfRenderWindow_drawSprite(windo->window, back->my_bottom1, NULL);
    sfSprite_setPosition(back->my_bottom, back->position_bott);
    sfRenderWindow_drawSprite(windo->window, back->my_bottom, NULL);
}

void death(gather_t *gather)
{
    if (gather->enemy.death_i < 1)
        sfSound_play(gather->sound.death);
    back_death(&gather->back, &gather->windo);
    pipe_death(gather->windo.window, &gather->enemy);
    update_gm_over(gather);
    gather->menu.stop_game = 1;
    gather->enemy.death_i = 1;
}
