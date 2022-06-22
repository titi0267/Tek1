/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** manage_options_fill
*/

#include "../../../include/func_name.h"

void manage_fill_fps(rpg_t *rpg)
{
    sfSprite_setTexture(rpg->menu->stg->graph->graph_btn->graphismes[FPS30],
    rpg->menu->stg->graph->graph_btn->empty_square, sfTrue);
    sfSprite_setTexture(rpg->menu->stg->graph->graph_btn->graphismes[FPS60],
    rpg->menu->stg->graph->graph_btn->empty_square, sfTrue);
    if (rpg->basic->cnf->scr_cnf->fps == 30) {
        sfSprite_setTexture
        (rpg->menu->stg->graph->graph_btn->graphismes[FPS30],
        rpg->menu->stg->graph->graph_btn->fill_square, sfTrue);
    }
    if (rpg->basic->cnf->scr_cnf->fps == 60) {
        sfSprite_setTexture
        (rpg->menu->stg->graph->graph_btn->graphismes[FPS60],
        rpg->menu->stg->graph->graph_btn->fill_square, sfTrue);
    }
}

void manage_fill_resolution(rpg_t *rpg)
{
    sfVector2u size2 = {1280, 720};
    sfVector2u size3 = {1160, 630};

    if (rpg->basic->cnf->scr_cnf->resolution == 1) {
        sfSprite_setTexture
        (rpg->menu->stg->graph->graph_btn->graphismes[RES12x20],
        rpg->menu->stg->graph->graph_btn->fill_square, sfTrue);
        sfRenderWindow_setSize(rpg->basic->wnd->my_wnd, size2);
    }
    if (rpg->basic->cnf->scr_cnf->resolution == 2) {
        sfSprite_setTexture
        (rpg->menu->stg->graph->graph_btn->graphismes[RES11x30],
        rpg->menu->stg->graph->graph_btn->fill_square, sfTrue);
        sfRenderWindow_setSize(rpg->basic->wnd->my_wnd, size3);
    }
    manage_fill_fps(rpg);
}