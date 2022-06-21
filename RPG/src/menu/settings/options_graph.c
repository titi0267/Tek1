/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** options_graph
*/

#include "../../../include/func_name.h"

void clic_menu(rpg_t *rpg)
{
    if (rpg->basic->evt->event.type == sfEvtMouseButtonPressed) {
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 255)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 361.5)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 789)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 460)))
            rpg->menu->stg->stg_scene = GRAPH_SCN;
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 255)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 460.5)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 789)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 559.5)))
            rpg->menu->stg->stg_scene = SOUND_SCN;
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 255)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 559.5)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 789)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 658.5)))
            rpg->menu->stg->stg_scene = KEYS_SCN;
    }
}

void select_resolution(rpg_t *rpg)
{
    if (rpg->basic->evt->event.type == sfEvtMouseButtonPressed) {
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1589.804)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 613.25)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1614.304)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 637.75)))
            rpg->basic->cnf->scr_cnf->resolution = 0;
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1589.804)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 583.75)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1614.304)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 597.25)))
            rpg->basic->cnf->scr_cnf->resolution = 1;
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1589.804)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 530.25)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1614.304)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 554.75)))
            rpg->basic->cnf->scr_cnf->resolution = 2;
    }
}

void select_fps(rpg_t *rpg)
{
    if (rpg->basic->evt->event.type == sfEvtMouseButtonPressed) {
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1477.554)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 382.25)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1502.054)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 406.75)))
            rpg->basic->cnf->scr_cnf->fps = 30;
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1631.554)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 382.25)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1656.054)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 406.75)))
            rpg->basic->cnf->scr_cnf->fps = 60;
    }
}

void draw_square(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->menu->stg->graph->graph_btn->graphismes[RES19x80], NULL);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->menu->stg->graph->graph_btn->graphismes[RES12x20], NULL);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->menu->stg->graph->graph_btn->graphismes[RES11x30], NULL);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->menu->stg->graph->graph_btn->graphismes[FPS60], NULL);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->menu->stg->graph->graph_btn->graphismes[FPS30], NULL);
}

void manage_window_size(rpg_t *rpg)
{
    sfVector2u size1 = {1920, 1080};

    sfSprite_setTexture(rpg->menu->stg->graph->graph_btn->graphismes[RES19x80],
    rpg->menu->stg->graph->graph_btn->empty_square, sfTrue);
    sfSprite_setTexture(rpg->menu->stg->graph->graph_btn->graphismes[RES12x20],
    rpg->menu->stg->graph->graph_btn->empty_square, sfTrue);
    sfSprite_setTexture(rpg->menu->stg->graph->graph_btn->graphismes[RES11x30],
    rpg->menu->stg->graph->graph_btn->empty_square, sfTrue);
    if (rpg->basic->cnf->scr_cnf->resolution == 0) {
        sfSprite_setTexture
        (rpg->menu->stg->graph->graph_btn->graphismes[RES19x80],
        rpg->menu->stg->graph->graph_btn->fill_square, sfTrue);
        sfRenderWindow_setSize(rpg->basic->wnd->my_wnd, size1);
    }
    manage_fill_resolution(rpg);
}