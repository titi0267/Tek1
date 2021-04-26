/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** cinematics
*/

#include "../../include/func_name.h"

void radio_rect(rpg_t *rpg)
{
    if (rpg->game->start->radio_offset <= 8) {
            rpg->game->start->radio_rect.left =
            rpg->game->start->radio_offset *
            rpg->game->start->radio_rect.width;
            rpg->game->start->radio_rect.top =
            rpg->game->start->radio_line *
            rpg->game->start->radio_rect.height;
            rpg->game->start->radio_offset++;
    }
    if (rpg->game->start->radio_offset == 8) {
        rpg->game->start->radio_line++;
        if (rpg->game->start->radio_line == 3)
            rpg->game->start->radio_line = 0;
        rpg->game->start->radio_offset = 0;
    }
}

void background_radio(rpg_t *rpg)
{
    static float nbr = 0;

    if (nbr > 2.5 && rpg->game->start->wait_radio == 0) {
        rpg->game->start->radio_offset += 1;
        rpg->game->start->wait_radio = 1;
        nbr = 0;
    }
    if (nbr > 0.2 && rpg->game->start->wait_radio == 1) {
        radio_rect(rpg);
        nbr = 0;
    }
    sfSprite_setTextureRect(rpg->game->start->radio,
    rpg->game->start->radio_rect);
    nbr += rpg->basic->cnf->clk->time_loop;
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->game->start->radio, NULL);
}

void cinematic_1(rpg_t *rpg)
{
    static int set_voice = 0;

    if (set_voice == 0) {
        sfSound_play(rpg->game->start->cinematic_1);
        set_voice = 1;
    }
    if (sfSound_getStatus(rpg->game->start->cinematic_1) == sfPlaying) {
        if (rpg->basic->evt->event.type == sfEvtKeyReleased &&
        rpg->basic->evt->event.key.code == sfKeySpace)
            sfSound_stop(rpg->game->start->cinematic_1);
        background_radio(rpg);
    }
}