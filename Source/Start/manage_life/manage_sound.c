/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** manage_sound
*/

#include "../../../include/defender.h"

void manage_sound_game_bis(core_t *core)
{
    sfSound_setBuffer(core->menu->stg->vol->kill,
                    core->menu->stg->vol->buffer_kill);
    sfSound_setBuffer(core->menu->stg->vol->nxt_lvl,
                    core->menu->stg->vol->buffer_level);
    sfSound_setBuffer(core->menu->stg->vol->laugh,
                    core->menu->stg->vol->buffer_laugh);
    sfSound_setBuffer(core->menu->stg->vol->gameover,
                    core->menu->stg->vol->buffer_gameover);
    sfSound_setVolume(core->menu->stg->vol->kill, 15.00);
    sfSound_setVolume(core->menu->stg->vol->nxt_lvl, 15.00);
    sfSound_setVolume(core->menu->stg->vol->laugh, 15.00);
    sfSound_setVolume(core->menu->stg->vol->gameover, 15.00);
}

void manage_sound_game(core_t *core)
{
    core->menu->stg->vol->buffer_kill =
        sfSoundBuffer_createFromFile("Ressources/Sound/kill.ogg");
    core->menu->stg->vol->buffer_level =
        sfSoundBuffer_createFromFile("Ressources/Sound/lvl.ogg");
    core->menu->stg->vol->buffer_laugh =
        sfSoundBuffer_createFromFile("Ressources/Sound/laugh.ogg");
    core->menu->stg->vol->buffer_gameover =
        sfSoundBuffer_createFromFile("Ressources/Sound/game_over.ogg");
    core->menu->stg->vol->kill = sfSound_create();
    core->menu->stg->vol->nxt_lvl = sfSound_create();
    core->menu->stg->vol->laugh = sfSound_create();
    core->menu->stg->vol->gameover = sfSound_create();
    manage_sound_game_bis(core);
}
