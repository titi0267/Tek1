/*
** EPITECH PROJECT, 2021
** sound by Timothy CONIEL
** File description:
** sound.c
*/
#include "../include/my.h"

void create_sound(sound_t *sound)
{
    sound->coin = sfSound_create();
    sound->coin_buf = sfSoundBuffer_createFromFile("png/coin_sound.ogg");
    sfSound_setBuffer(sound->coin, sound->coin_buf);
    sound->death = sfSound_create();
    sound->death_buf = sfSoundBuffer_createFromFile("png/death_sound.ogg");
    sfSound_setBuffer(sound->death, sound->death_buf);
    sound->jump = sfSound_create();
    sound->jump_buf = sfSoundBuffer_createFromFile("png/jump_sound.ogg");
    sfSound_setBuffer(sound->jump, sound->jump_buf);
}

void bird_after_pipe(gather_t *gather)
{
    while (gather->bird.aft_pip <= 16) {
        if (gather->bird.collision[gather->bird.aft_pip].x < 170 &&
            gather->bird.collision[gather->bird.aft_pip].x >= 166)
            break;
        gather->bird.aft_pip++;
    }
    if (gather->bird.aft_pip != 17) {
        sfSound_play(gather->sound.coin);
        gather->score.amount++;
    }
    gather->bird.aft_pip = 1;
}

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