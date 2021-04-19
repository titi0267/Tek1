/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** move_characters
*/

#include "../../../include/func_name.h"

void move_characters(rpg_t *rpg, int charac)
{
    int i = 0;

    if (i < 4) {
        rpg->menu->main_menu->new_game->rect_characters.width += i * 259;
        i++;
    } else
        i = 0;
    sfSprite_setTextureRect(rpg->menu->main_menu->new_game->characters[charac],
    rpg->menu->main_menu->new_game->rect_characters);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->menu->main_menu->new_game->characters[charac], NULL);
}