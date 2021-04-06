/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** main_menu
*/

#include "../../include/rpg.h"

int main_menu(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->basics->my_window,
    rpg->main_menu->main_menu, NULL);
    sfRenderWindow_drawSprite(rpg->basics->my_window,
    rpg->main_menu->menu[NONE], NULL);
    hitbox1(rpg);
    hitbox2(rpg);
    clic1(rpg);
}