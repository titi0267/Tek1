/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** init_cinematic2
*/

#include "../../../include/func_name.h"

static void init_rect_road(rpg_t *rpg)
{
    rpg->game->end->road_rect.left = 0;
    rpg->game->end->road_rect.width = 1920;
    rpg->game->end->road_rect.height = 1080;
    rpg->game->end->road_rect.top = 0;
    rpg->game->end->road_line = 0;
    rpg->game->end->road_offset = 0;
}

void init_road_spt(rpg_t *rpg)
{
    sfTexture *road_tex = sfTexture_createFromFile
    ("assets/cinematics/autoroute.jpg", NULL);

    rpg->game->end->road = sfSprite_create();
    sfSprite_setTexture(rpg->game->end->road,
    road_tex, sfTrue);
    rpg->game->end->wait_road = 0;
    init_rect_road(rpg);
}

void init_cinematic2_audio(rpg_t *rpg)
{
    rpg->game->end->cine2 =
    sfSoundBuffer_createFromFile("assets/audios/cinematic2.ogg");
    rpg->game->end->cinematic_2 = sfSound_create();
    sfSound_setBuffer(rpg->game->end->cinematic_2,
    rpg->game->end->cine2);
    sfSound_setVolume(rpg->game->end->cinematic_2, 65);
}

void init_credits(rpg_t *rpg)
{
    sfTexture *cred = sfTexture_createFromFile
    ("assets/cinematics/credits.png", NULL);

    rpg->game->end->pos_credits.x = 0;
    rpg->game->end->pos_credits.y = 1080;
    rpg->game->end->credits = sfSprite_create();
    sfSprite_setTexture(rpg->game->end->credits,
    cred, sfTrue);
    sfSprite_setPosition(rpg->game->end->credits, rpg->game->end->pos_credits);
}