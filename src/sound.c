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
    static int i = 1;

    while (i <= 16) {
        if (gather->bird.collision[i].x < 170 &&
            gather->bird.collision[i].x >= 166)
            break;
        i++;
    }
    if (i != 17) {
        sfSound_play(gather->sound.coin);
        gather->score.amount++;
    }
    i = 1;
}

void death(gather_t *gather)
{
    static int i = 0;

    if (i < 1)
        sfSound_play(gather->sound.death);
    i = 1;
}