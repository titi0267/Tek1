/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** choose_perso
*/

#include "../../../include/func_name.h"

void hover_perso1(rpg_t *rpg)
{
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 396)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 362)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 645)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 709))) {
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->menu->main_menu->new_game->select[MAXOU], NULL);
        move_characters(rpg, MAXOU);
    }
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 689)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 362)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 938)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 709))) {
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->menu->main_menu->new_game->select[TIMO], NULL);
    }
}

void hover_perso2(rpg_t *rpg)
{
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 982)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 362)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1231)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 709))) {
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->menu->main_menu->new_game->select[LUDO], NULL);
    }
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1275)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 362)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1524)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 709))) {
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->menu->main_menu->new_game->select[SYLVIE], NULL);
    }
}

void select_characters2(rpg_t *rpg)
{
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 982)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 362)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1231)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 709))) {
        rpg->game->character_chosen = LUDO;
        rpg->menu->status = ON_GAME;
    }
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1275)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 362)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1524)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 709))) {
        rpg->game->character_chosen = SYLVIE;
        rpg->menu->status = ON_GAME;
    }
}

void select_characters(rpg_t *rpg)
{
    if (rpg->basic->evt->event.type == sfEvtMouseButtonPressed) {
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 396)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 362)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 645)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 709))) {
            rpg->game->character_chosen = MAXOU;
            rpg->menu->status = ON_GAME;
        }
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 689)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 362)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 938)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 709))) {
            rpg->game->character_chosen = TIMO;
            rpg->menu->status = ON_GAME;
        }
        select_characters2(rpg);
    }
}

void choose_perso(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->menu->main_menu->new_game->background, NULL);
    hover_perso1(rpg);
    hover_perso2(rpg);
    select_characters(rpg);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        rpg->menu->status = ON_MENU;
}