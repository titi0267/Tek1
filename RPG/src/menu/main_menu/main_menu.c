/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** main_menu
*/

#include "../../../include/func_name.h"

int main_menu(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->menu->main_menu->menu_spt->main_menu, NULL);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->menu->main_menu->menu_spt->menu[NONE], NULL);
    hitbox1(rpg);
    hitbox2(rpg);
    if (clic1(rpg) == -1)
        return (-1);
    return (0);
}