/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** background
*/

#include "../../include/rpg.h"

int background(rpg_t *rpg)
{
    static float nbr = 0;

    printf("nbr = %f\n", nbr);
    if (nbr > 1) {
        if (rpg->main_menu->offset < 24) {
            rpg->main_menu->offset++;
            rpg->main_menu->rect_but.left = rpg->main_menu->offset *
            rpg->main_menu->rect_but.width;
            if (rpg->main_menu->offset == 9)
                rpg->main_menu->rect_but.top = 1080;
            if (rpg->main_menu->offset == 17)
                rpg->main_menu->rect_but.top = 2160;
        }
        nbr = 0;
    }
    //sfSprite_setTextureRect(rpg->main_menu->background,
    //rpg->main_menu->rect_but);
    nbr += rpg->basics->time_loop;
    sfRenderWindow_drawSprite(rpg->basics->my_window,
    rpg->main_menu->background, NULL);
}