/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** manage_sound
*/

#include "../../../include/defender.h"

void sound_kill(core_t *core)
{
    sfSoundBuffer *soundbuffer = sfSoundBuffer_createFromFile("Ressources/Sound/call-of-duty-modern-warfare-2019warzone-kill-sound-effect.ogg");
    sfSound *kill = sfSound_create();

    sfSound_setBuffer(kill, soundbuffer);
    sfSound_setVolume(kill, 15.00);
    sfSound_play(kill);
}

void sound_nextlvl(core_t *core)
{
    sfSoundBuffer *soundbuffer = sfSoundBuffer_createFromFile("Ressources/Sound/level-up-sound-effect.ogg");
    sfSound *nxt_lvl = sfSound_create();

    sfSound_setBuffer(nxt_lvl, soundbuffer);
    sfSound_setVolume(nxt_lvl, 15.00);
    sfSound_play(nxt_lvl);
}
