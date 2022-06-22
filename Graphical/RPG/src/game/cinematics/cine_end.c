/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** cine_end
*/

#include "../../../include/func_name.h"

static void road_rect(rpg_t *rpg)
{
    if (rpg->game->end->road_offset <= 8) {
            rpg->game->end->road_rect.left =
            rpg->game->end->road_offset *
            rpg->game->end->road_rect.width;
            rpg->game->end->road_rect.top =
            rpg->game->end->road_line *
            rpg->game->end->road_rect.height;
            rpg->game->end->road_offset++;
    }
    if (rpg->game->end->road_offset == 8) {
        rpg->game->end->road_line++;
        if (rpg->game->end->road_line == 3)
            rpg->game->end->road_line = 0;
        rpg->game->end->road_offset = 0;
    }
}

static void background_road(rpg_t *rpg)
{
    static float nbr = 0;

    if (rpg->game->end->wait_road == 0) {
        rpg->game->end->road_offset += 1;
        rpg->game->end->wait_road = 1;
        nbr = 0;
    }
    if (nbr > 0.07 && rpg->game->end->wait_road == 1) {
        road_rect(rpg);
        nbr = 0;
    }
    sfSprite_setTextureRect(rpg->game->end->road,
    rpg->game->end->road_rect);
    nbr += rpg->basic->cnf->clk->time_loop;
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->game->end->road, NULL);
}

void cinematic_2(rpg_t *rpg)
{
    if (rpg->game->end->status_cinematic2 == FALSE) {
        sfSound_play(rpg->game->end->cinematic_2);
        rpg->game->end->status_cinematic2 = TRUE;
    }
    if (sfSound_getStatus(rpg->game->end->cinematic_2) == sfPlaying) {
        if (rpg->basic->evt->event.type == sfEvtKeyReleased &&
        rpg->basic->evt->event.key.code == sfKeySpace)
            sfSound_stop(rpg->game->end->cinematic_2);
        background_road(rpg);
    }
}

void credits(rpg_t *rpg)
{
    static float nbr = 0;

    nbr += rpg->basic->cnf->clk->time_loop;
    if (nbr > 0.1) {
        rpg->game->end->pos_credits.y -= 7;
        nbr = 0;
    }
    sfSprite_setPosition(rpg->game->end->credits, rpg->game->end->pos_credits);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->game->end->credits, NULL);
}