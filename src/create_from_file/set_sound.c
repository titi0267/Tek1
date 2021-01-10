/*
** EPITECH PROJECT, 2021
** set sound by Timothy CONIEL
** File description:
** set_sound.c
*/
#include "../../include/my.h"

void create_sound(sound_t *sound)
{
    sound->coin = sfSound_create();
    sound->coin_buf = sfSoundBuffer_createFromFile("ressource/sound/coin.ogg");
    sfSound_setBuffer(sound->coin, sound->coin_buf);
    sound->death = sfSound_create();
    sound->death_buf = sfSoundBuffer_createFromFile(
                                                "ressource/sound/death.ogg");
    sfSound_setBuffer(sound->death, sound->death_buf);
    sound->jump = sfSound_create();
    sound->jump_buf = sfSoundBuffer_createFromFile("ressource/sound/jump.ogg");
    sfSound_setBuffer(sound->jump, sound->jump_buf);
    sound->out_gm = sfSound_create();
    sound->out_gm_buf = sfSoundBuffer_createFromFile(
                                                    "ressource/sound/menu.ogg");
    sfSound_setBuffer(sound->out_gm, sound->out_gm_buf);
}
