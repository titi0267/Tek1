/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** vaccine_manager
*/

#include "../../../include/func_name.h"

void vaccine_manager(rpg_t *rpg)
{
    if (rpg->game->in_game->inventory->vaccine_status == TRUE) {
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->inventory->vaccine, NULL);
    }
}