/*
** EPITECH PROJECT, 2021
** set sound by Timothy CONIEL
** File description:
** set_sound.c
*/
#include "../../include/my.h"

void coin_sound(sound_t *sound)
{
    sound->coin = sfSound_create();
    sound->coin_buf = sfSoundBuffer_createFromFile("ressource/sound/coin.ogg");
    sfSound_setBuffer(sound->coin, sound->coin_buf);
}

void death_sound(sound_t *sound)
{
    sound->death = sfSound_create();
    sound->death_buf = sfSoundBuffer_createFromFile(
                                                "ressource/sound/death.ogg");
    sfSound_setBuffer(sound->death, sound->death_buf);
}

void jump_sound(sound_t *sound)
{
    sound->jump = sfSound_create();
    sound->jump_buf = sfSoundBuffer_createFromFile("ressource/sound/jump.ogg");
    sfSound_setBuffer(sound->jump, sound->jump_buf);
}

void game_over_sound(sound_t *sound)
{
    sound->out_gm = sfSound_create();
    sound->out_gm_buf = sfSoundBuffer_createFromFile(
                                                    "ressource/sound/menu.ogg");
    sfSound_setBuffer(sound->out_gm, sound->out_gm_buf);
}

void create_sound(sound_t *sound)
{
    coin_sound(sound);
    death_sound(sound);
    jump_sound(sound);
    game_over_sound(sound);
    sound->death_down= sfSound_create();
    sound->death_down_bu = sfSoundBuffer_createFromFile(
                                            "ressource/sound/death_down.ogg");
    sfSound_setBuffer(sound->death_down, sound->death_down_bu);
}
