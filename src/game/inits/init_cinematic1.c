/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** init_cinematic1
*/

#include "../../../include/func_name.h"

static void init_rect_radio(rpg_t *rpg)
{
    rpg->game->start->radio_rect.left = 0;
    rpg->game->start->radio_rect.width = 1920;
    rpg->game->start->radio_rect.height = 1080;
    rpg->game->start->radio_rect.top = 0;
    rpg->game->start->radio_line = 0;
    rpg->game->start->radio_offset = 0;
}

void init_radio_spt(rpg_t *rpg)
{
    sfTexture *radio_tex = sfTexture_createFromFile
    ("assets/cinematics/télé.jpg", NULL);

    rpg->game->start->radio = sfSprite_create();
    sfSprite_setTexture(rpg->game->start->radio,
    radio_tex, sfTrue);
    rpg->game->start->wait_radio = 0;
    init_rect_radio(rpg);
}

void init_cinematic1_audio(rpg_t *rpg)
{
    rpg->game->start->cine1 =
    sfSoundBuffer_createFromFile("assets/audios/cinematic1.ogg");
    rpg->game->start->cinematic_1 = sfSound_create();
    sfSound_setBuffer(rpg->game->start->cinematic_1,
    rpg->game->start->cine1);
    sfSound_setVolume(rpg->game->start->cinematic_1, 65);
}