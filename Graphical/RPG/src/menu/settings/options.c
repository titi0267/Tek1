/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** options
*/

#include "../../../include/func_name.h"

void clic_options(rpg_t *rpg)
{
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 255)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 361.5)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 789)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 460)))
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->menu->stg->opt[GRAPH], NULL);
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 255)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 460.5)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 789)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 559.5)))
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->menu->stg->opt[SOUND], NULL);
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 255)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 559.5)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 789)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 658.5)))
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->menu->stg->opt[GAME_OPTIONS], NULL);
}

void clic_options1(rpg_t *rpg)
{
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 255)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 684.5)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 789)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 783.5)))
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->menu->stg->opt[MAIN_MENU], NULL);
    if (rpg->basic->evt->event.type == sfEvtMouseButtonPressed) {
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 255)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 684.5)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 789)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 783.5)))
            rpg->menu->status = ON_MENU;
    }
}

int show_menus(rpg_t *rpg)
{
    if (rpg->menu->stg->stg_scene == GRAPH_SCN) {
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->menu->stg->opt[GRAPH_F], NULL);
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->menu->stg->opt[GRAPH], NULL);
        draw_square(rpg);
        select_fps(rpg);
        select_resolution(rpg);
        manage_window_size(rpg);
        return (-1);
    }
    if (rpg->menu->stg->stg_scene == SOUND_SCN) {
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->menu->stg->opt[SOUND_F], NULL);
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->menu->stg->opt[SOUND], NULL);
        manage_sound(rpg);
        return (-1);
    }
    return (0);
}

int show_menus2(rpg_t *rpg)
{
    if (rpg->menu->stg->stg_scene == KEYS_SCN) {
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->menu->stg->opt[GAME_OPTIONS_F], NULL);
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->menu->stg->opt[GAME_OPTIONS], NULL);
        manage_key(rpg);
        return (-1);
    }
    return (0);
}

void options(rpg_t *rpg)
{
    show_menus(rpg);
    show_menus2(rpg);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->menu->stg->opt[NO], NULL);
    clic_menu(rpg);
    clic_options(rpg);
    clic_options1(rpg);
}