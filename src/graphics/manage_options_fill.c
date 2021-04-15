/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** manage_options_fill
*/

#include "../../include/func_name.h"

void manage_fill_fps(rpg_t *rpg)
{
    sfSprite_setTexture(rpg->menu->stg->graph->graph_btn->graphismes[FPS30],
    rpg->menu->stg->graph->graph_btn->empty_square, sfTrue);
    sfSprite_setTexture(rpg->menu->stg->graph->graph_btn->graphismes[FPS60],
    rpg->menu->stg->graph->graph_btn->empty_square, sfTrue);
    if (rpg->basic->cnf->scr_cnf->fps == 30) {
        sfSprite_setTexture(rpg->menu->stg->graph->graph_btn->graphismes[FPS30],
        rpg->menu->stg->graph->graph_btn->fill_square, sfTrue);
    }
    if (rpg->basic->cnf->scr_cnf->fps == 60) {
        sfSprite_setTexture(rpg->menu->stg->graph->graph_btn->graphismes[FPS60],
        rpg->menu->stg->graph->graph_btn->fill_square, sfTrue);
    }
}

void manage_fill_resolution(rpg_t *rpg)
{
    sfVector2u size2 = {1280, 720};
    sfVector2u size3 = {1160, 630};

    if (rpg->basic->cnf->scr_cnf->resolution == 1) {
        sfSprite_setTexture(rpg->menu->stg->graph->graph_btn->graphismes[RES12x20],
        rpg->menu->stg->graph->graph_btn->fill_square, sfTrue);
        sfRenderWindow_setSize(rpg->basic->wnd->my_wnd, size2);
    }
    if (rpg->basic->cnf->scr_cnf->resolution == 2) {
        sfSprite_setTexture(rpg->menu->stg->graph->graph_btn->graphismes[RES11x30],
        rpg->menu->stg->graph->graph_btn->fill_square, sfTrue);
        sfRenderWindow_setSize(rpg->basic->wnd->my_wnd, size3);
    }
    manage_fill_fps(rpg);
}

void show_music_sound(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd
    ,rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_MUSIC], NULL);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd
    ,rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_DIAG], NULL);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd
    ,rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_AMBT], NULL);
}

void manage_sound(rpg_t *rpg)
{
    sfFloatRect music = sfSprite_getGlobalBounds
    (rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_MUSIC]);
    sfVector2f sp_center = {music.width / 2, music.height / 2};
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(rpg->basic->wnd->my_wnd,
    sfMouse_getPositionRenderWindow(rpg->basic->wnd->my_wnd), NULL);
    //sfBool hover = sfFloatRect_contains(
    //&rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_MUSIC], mouse.x, mouse.y);

    sfSprite_setOrigin(rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_MUSIC], sp_center);
    mouse.y = 363;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        // if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, music.left)) &&
        // ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, music.top)) &&
        // (rpg->basic->cnf->mouse.x <= adapt_x(rpg, music.left + music.width)) &&
        // (rpg->basic->cnf->mouse.y <= adapt_y(rpg, music.top + music.height)) &&
        // (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1678.51) &&
        // (rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1452.608)))
        //if (hover == sfTrue)
        //    sfSprite_setPosition(rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_MUSIC],
        //    mouse);
    }
}