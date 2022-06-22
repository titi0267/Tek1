/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** choose_perso
*/

#include "../../../include/func_name.h"

void display_character_at_stop(rpg_t *rpg, int charac)
{
    rpg->menu->main_menu->new_game->rect_characters[charac].left = 0;
    rpg->menu->main_menu->new_game->offset_character[charac] = 0;
    sfSprite_setTextureRect
    (rpg->menu->main_menu->new_game->characters[charac],
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