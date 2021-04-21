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
    } else
        display_character_at_stop(rpg, MAXOU);
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 689)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 362)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 938)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 709))) {
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->menu->main_menu->new_game->select[TIMO], NULL);
        move_characters(rpg, TIMO);
    } else
        display_character_at_stop(rpg, TIMO);
}

void hover_perso2(rpg_t *rpg)
{
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 982)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 362)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1231)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 709))) {
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->menu->main_menu->new_game->select[LUDO], NULL);
        move_characters(rpg, LUDO);
    } else
        display_character_at_stop(rpg, LUDO);
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1275)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 362)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1524)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 709))) {
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->menu->main_menu->new_game->select[SYLVIE], NULL);
        move_characters(rpg, SYLVIE);
    } else
        display_character_at_stop(rpg, SYLVIE);
}

void select_characters2(rpg_t *rpg)
{
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 982)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 362)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1231)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 709))) {
        rpg->menu->main_menu->new_game->character_chosen = LUDO;
        rpg->menu->status = ON_GAME;
    }
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1275)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 362)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1524)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 709))) {
        rpg->menu->main_menu->new_game->character_chosen = SYLVIE;
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
            rpg->menu->main_menu->new_game->character_chosen = MAXOU;
            rpg->menu->status = ON_GAME;
        }
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 689)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 362)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 938)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 709))) {
            rpg->menu->main_menu->new_game->character_chosen = TIMO;
            rpg->menu->status = ON_GAME;
        }
        select_characters2(rpg);
    }
}

void display_character_at_stop(rpg_t *rpg, int charac)
{
    rpg->menu->main_menu->new_game->rect_characters[charac].left = 0;
    rpg->menu->main_menu->new_game->offset_character[charac] = 0;
    sfSprite_setTextureRect(rpg->menu->main_menu->new_game->characters[charac],
    rpg->menu->main_menu->new_game->rect_characters[charac]);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->menu->main_menu->new_game->characters[charac], NULL);
}

void choose_perso(rpg_t *rpg)
{
    sfSprite_setTextureRect(rpg->menu->main_menu->new_game->characters[MAXOU],
    rpg->menu->main_menu->new_game->rect_characters[MAXOU]);
    sfSprite_setTextureRect(rpg->menu->main_menu->new_game->characters[LUDO],
    rpg->menu->main_menu->new_game->rect_characters[LUDO]);
    sfSprite_setTextureRect(rpg->menu->main_menu->new_game->characters[SYLVIE],
    rpg->menu->main_menu->new_game->rect_characters[SYLVIE]);
    sfSprite_setTextureRect(rpg->menu->main_menu->new_game->characters[TIMO],
    rpg->menu->main_menu->new_game->rect_characters[TIMO]);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->menu->main_menu->new_game->background, NULL);
    if (rpg->basic->cnf->clk->time_menu >= 0.2)
        select_characters(rpg);
    hover_perso1(rpg);
    hover_perso2(rpg);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        rpg->menu->status = ON_MENU;
}