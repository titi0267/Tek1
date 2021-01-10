/*
** EPITECH PROJECT, 2021
** destroy all by Timothy CONIEL
** File description:
** destroy_all.c
*/
#include "../../include/my.h"

void destroy_alias(gather_t *gather)
{
    sfSprite_destroy(gather->enemy.my_pipe_d);
    sfSprite_destroy(gather->enemy.my_pipe_u);
    sfSprite_destroy(gather->enemy.my_pipe);
    sfTexture_destroy(gather->enemy.pipe_tex);
    sfTexture_destroy(gather->enemy.pipe_tex_d);
    sfTexture_destroy(gather->enemy.pipe_tex_u);
    sfSprite_destroy(gather->bird.my_bird);
    sfTexture_destroy(gather->bird.bird_tex);
    sfSprite_destroy(gather->back.my_bottom);
    sfTexture_destroy(gather->back.bottom);
    sfSprite_destroy(gather->back.my_background);
    sfTexture_destroy(gather->back.background1);
    sfSprite_destroy(gather->back.my_background1);
    sfTexture_destroy(gather->back.background);
    sfSprite_destroy(gather->back.my_bottom1);
    sfTexture_destroy(gather->back.bottom1);
}

void destroy_alias1(gather_t *gather)
{
    sfSprite_destroy(gather->menu.button);
    sfSprite_destroy(gather->menu.black_but);
    sfSprite_destroy(gather->menu.load);
    sfSprite_destroy(gather->menu.gm_ovr);
    sfTexture_destroy(gather->menu.loading);
    sfTexture_destroy(gather->menu.black_tex);
    sfTexture_destroy(gather->menu.game_ovr);
    sfTexture_destroy(gather->menu.button_tex);
    sfSound_destroy(gather->sound.out_gm);
    sfSoundBuffer_destroy(gather->sound.out_gm_buf);
    sfText_destroy(gather->score.your_score);
    sfText_destroy(gather->score.high_score);
    sfText_destroy(gather->score.text);
    sfText_destroy(gather->score.text_increase);
    sfText_destroy(gather->score.text_score);
    sfText_destroy(gather->menu.press);
    sfText_destroy(gather->menu.count);
    sfFont_destroy(gather->menu.font);
    sfFont_destroy(gather->score.font);
}

void destroy(gather_t *gather)
{
    destroy_alias(gather);
    destroy_alias1(gather);
    free(gather->enemy.pos);
    free(gather->enemy.pos_d);
    free(gather->enemy.pos_u);
    free(gather->bird.collision);
    sfClock_destroy(gather->time.clock);
    sfSound_destroy(gather->sound.coin);
    sfSoundBuffer_destroy(gather->sound.coin_buf);
    sfSound_destroy(gather->sound.jump);
    sfSoundBuffer_destroy(gather->sound.jump_buf);
    sfSound_destroy(gather->sound.death);
    sfSoundBuffer_destroy(gather->sound.death_buf);
}
