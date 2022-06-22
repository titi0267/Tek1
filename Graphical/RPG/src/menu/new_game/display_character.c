/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** display_character
*/

#include "../../../include/func_name.h"

void move_characters(rpg_t *rpg, int charac)
{
    static float nbr = 0;

    sfSprite_setTextureRect(rpg->menu->main_menu->new_game->characters[charac],
    rpg->menu->main_menu->new_game->rect_characters[charac]);
    nbr += rpg->basic->cnf->clk->time_loop;
    if (nbr >= 0.2) {
        rpg->menu->main_menu->new_game->offset_character[charac] += 1;
        rpg->menu->main_menu->new_game->rect_characters[charac].left =
        rpg->menu->main_menu->new_game->offset_character[charac] *
        rpg->menu->main_menu->new_game->rect_characters[charac].width;
        nbr = 0;
    }
    if (rpg->menu->main_menu->new_game->offset_character[charac] == 3)
        rpg->menu->main_menu->new_game->offset_character[charac] = 0;
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->menu->main_menu->new_game->characters[charac], NULL);
}

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
        set_player_rect(rpg);
        rpg->menu->status = ON_CINEMATIC1;
    }
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1275)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 362)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1524)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 709))) {
        rpg->menu->main_menu->new_game->character_chosen = SYLVIE;
        set_player_rect(rpg);
        rpg->menu->status = ON_CINEMATIC1;
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
            set_player_rect(rpg);
            rpg->menu->status = ON_CINEMATIC1;
        }
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 689)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 362)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 938)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 709))) {
            rpg->menu->main_menu->new_game->character_chosen = TIMO;
            set_player_rect(rpg);
            rpg->menu->status = ON_CINEMATIC1;
        }
        select_characters2(rpg);
    }
}
