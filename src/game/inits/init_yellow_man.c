/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** init_yellow_man
*/

#include "../../../include/func_name.h"
//
//58.6 x 88

void init_nmi_side(rpg_t *rpg)
{
    rpg->game->in_game->nmi_list->nmi_rect[LEFT].left = 0;
    rpg->game->in_game->nmi_list->nmi_rect[LEFT].top = 88;
    rpg->game->in_game->nmi_list->nmi_rect[LEFT].width = 58;
    rpg->game->in_game->nmi_list->nmi_rect[LEFT].height = 88;
    rpg->game->in_game->nmi_list->nmi_rect[RIGHT].left = 0;
    rpg->game->in_game->nmi_list->nmi_rect[RIGHT].top = 88 * 3;
    rpg->game->in_game->nmi_list->nmi_rect[RIGHT].width = 58;
    rpg->game->in_game->nmi_list->nmi_rect[RIGHT].height = 88;
}

void init_nmi_up_down(rpg_t *rpg)
{
    rpg->game->in_game->nmi_list->nmi_rect[UP].left = 0;
    rpg->game->in_game->nmi_list->nmi_rect[UP].top = 88 * 2;
    rpg->game->in_game->nmi_list->nmi_rect[UP].width = 58;
    rpg->game->in_game->nmi_list->nmi_rect[UP].height = 88;
    rpg->game->in_game->nmi_list->nmi_rect[DOWN].left = 0;
    rpg->game->in_game->nmi_list->nmi_rect[DOWN].top = 0;
    rpg->game->in_game->nmi_list->nmi_rect[DOWN].width = 58;
    rpg->game->in_game->nmi_list->nmi_rect[DOWN].height = 88;
    init_nmi_side(rpg);
}

int rect_nmi(rpg_t *rpg)
{
    if ((rpg->game->in_game->nmi_list->offset_nmi = malloc(sizeof(int) * 5)) == NULL)
        return (MALLOC_ERROR);
    for (int i = UP; i <= LEFT; i++)
        rpg->game->in_game->nmi_list->offset_nmi[i] = 0;
    rpg->game->in_game->nmi_list->last_pos = 0;
    rpg->game->in_game->nmi_list->clock_rect = 0;
    return (0);
}

int init_yellow_man(rpg_t *rpg)
{
    sfTexture *yellow = sfTexture_createFromFile("assets/perso/yellow_man.png",
    NULL);

    rpg->game->in_game->nmi_list->yellow_man = sfSprite_create();
    sfSprite_setTexture(rpg->game->in_game->nmi_list->yellow_man, yellow, sfTrue);
    if ((rpg->game->in_game->nmi_list->nmi_rect =
    malloc(sizeof(sfIntRect) * 5)) == NULL)
        return (MALLOC_ERROR);
    init_nmi_up_down(rpg);
    for (int i = UP; i <= LEFT; i++)
        sfSprite_setTextureRect(rpg->game->in_game->nmi_list->yellow_man,
        rpg->game->in_game->nmi_list->nmi_rect[i]);
    rect_nmi(rpg);
    return (0);
}