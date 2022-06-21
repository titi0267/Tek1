/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** manage_sound
*/

#include "../../../include/defender.h"

void destroy_sound(volume_t *vol)
{
    sfSoundBuffer_destroy(vol->buffer_kill);
    sfSoundBuffer_destroy(vol->buffer_level);
    sfSoundBuffer_destroy(vol->buffer_laugh);
    sfSoundBuffer_destroy(vol->buffer_gameover);
    sfSoundBuffer_destroy(vol->buffer_music);
    sfSound_destroy(vol->kill);
    sfSound_destroy(vol->nxt_lvl);
    sfSound_destroy(vol->laugh);
    sfSound_destroy(vol->gameover);
    sfSound_destroy(vol->music);
}

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
    sfSound_setBuffer(core->menu->stg->vol->music,
                    core->menu->stg->vol->buffer_music);
    sfSound_setVolume(core->menu->stg->vol->music,
                    core->menu->stg->vol->level_vol);
    sfSound_setVolume(core->menu->stg->vol->kill,
                    core->menu->stg->vol->level_vol);
    sfSound_setVolume(core->menu->stg->vol->nxt_lvl,
                    core->menu->stg->vol->level_vol);
    sfSound_setVolume(core->menu->stg->vol->laugh,
                    core->menu->stg->vol->level_vol);
    sfSound_setVolume(core->menu->stg->vol->gameover,
                    core->menu->stg->vol->level_vol);
}

void manage_sound_game_bis_bis(core_t *core)
{
    core->menu->stg->vol->music = sfSound_create();
    core->menu->stg->vol->kill = sfSound_create();
    core->menu->stg->vol->nxt_lvl = sfSound_create();
    core->menu->stg->vol->laugh = sfSound_create();
    core->menu->stg->vol->gameover = sfSound_create();
}

void manage_sound_game(core_t *core)
{
    if (core->menu->init_music == FALSE) {
        core->menu->stg->vol->buffer_kill =
            sfSoundBuffer_createFromFile("Ressources/Sound/kill.ogg");
        core->menu->stg->vol->buffer_level =
            sfSoundBuffer_createFromFile("Ressources/Sound/lvl.ogg");
        core->menu->stg->vol->buffer_laugh =
            sfSoundBuffer_createFromFile("Ressources/Sound/laugh.ogg");
        core->menu->stg->vol->buffer_gameover =
            sfSoundBuffer_createFromFile("Ressources/Sound/game_over.ogg");
        core->menu->stg->vol->buffer_music =
            sfSoundBuffer_createFromFile("Ressources/Sound/music.ogg");
        manage_sound_game_bis_bis(core);
        manage_sound_game_bis(core);
        core->menu->init_music = TRUE;
    } else if (core->menu->pause_on == TRUE) {
        if (core->menu->tmp_pause == TRUE) {
            destroy_sound(core->menu->stg->vol);
            core->menu->init_music = FALSE;
            core->menu->tmp_pause = FALSE;
        }
    }
}
