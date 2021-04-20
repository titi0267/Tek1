/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** move_characters
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