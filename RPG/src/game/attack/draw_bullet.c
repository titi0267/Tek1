/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** draw_bullet
*/

#include "../../../include/func_name.h"

void draw_bullet(rpg_t *rpg)
{
    rpg->game->in_game->bullet_list = *(rpg->game->in_game->bullet);

    for (; rpg->game->in_game->bullet_list != NULL;
    rpg->game->in_game->bullet_list = rpg->game->in_game->bullet_list->next) {
        sfSprite_setPosition(rpg->game->in_game->bullet_list->bullet,
        rpg->game->in_game->bullet_list->bullet_pos);
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->bullet_list->bullet, NULL);
        bullet_direction(rpg, rpg->game->in_game->bullet_list);
    }
}