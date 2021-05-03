/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** move_enemy
*/

#include "../../../include/func_name.h"

void enemy_stop(rpg_t *rpg)
{
    if (rpg->game->in_game->nmi_list->last_pos != -1) {
        rpg->game->in_game->nmi_list->nmi_rect
        [rpg->game->in_game->nmi_list->last_pos].left = 58;
        sfSprite_setTextureRect(rpg->game->in_game->nmi_list->yellow_man,
        rpg->game->in_game->nmi_list->nmi_rect[rpg->game->in_game->nmi_list->last_pos]);
    }
    for (int d = UP; d <=  RIGHT; d++) {
        rpg->game->in_game->nmi_list->nmi_rect[d].left = 58;
        rpg->game->in_game->nmi_list->offset_nmi[d] = 0;
    }
}

int add_nmi(rpg_t *rpg)
{
    if ((rpg->game->in_game->nmi_list = malloc(sizeof
    (*rpg->game->in_game->nmi_list))) == NULL)
        return (MALLOC_ERROR);
    if (init_yellow_man(rpg) == 84)
        return (MALLOC_ERROR);
    rpg->game->in_game->nmi_list->next = *rpg->game->in_game->nmi;
    *rpg->game->in_game->nmi = rpg->game->in_game->nmi_list;
}

void spawn_enemy(rpg_t *rpg)
{
    
}

void move_enemies(rpg_t *rpg)
{
    rpg->game->in_game->nmi_list = *(rpg->game->in_game->nmi);

    for (; rpg->game->in_game->nmi_list != NULL; rpg->game->in_game->nmi_list
    = rpg->game->in_game->nmi_list->next) {
        spawn_enemies(rpg);
        //if (range > 300) enemy_stop(rpg);
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->nmi_list->yellow_man, NULL);
    }
    //if (player passe en x = ? & y = ? sur map nbr ?) add new enemy a list
    //
}