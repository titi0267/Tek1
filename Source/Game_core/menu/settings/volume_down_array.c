/*
** EPITECH PROJECT, 2021
** volume down array by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** volume_down_array.c
*/

#include "../../../../include/defender.h"

void volume_down_spt(volume_t *vol)
{
    vol->down_tex = sfTexture_createFromFile(
                        "Ressources/My_defender/button/vol_down_spt.png",
                        NULL);
    vol->down_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f down_pos = {2220, 700};

    sfSprite_setTexture(vol->down_spt, vol->down_tex, sfFalse);
    sfSprite_setPosition(vol->down_spt, down_pos);
    sfSprite_setScale(vol->down_spt, scale);
}

void down_click_spt(volume_t *vol)
{
    vol->down_click_tex = sfTexture_createFromFile(
                        "Ressources/My_defender/button/down_vol_click.png",
                        NULL);
    vol->down_click_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f down_click_pos = {2220, 700};
    sfSprite_setTexture(vol->down_click_spt, vol->down_click_tex, sfFalse);
    sfSprite_setPosition(vol->down_click_spt, down_click_pos);
    sfSprite_setScale(vol->down_click_spt, scale);
}

void hover_down_spt(volume_t *vol)
{
    vol->hover_down_tex = sfTexture_createFromFile(
                        "Ressources/My_defender/button/hover_down_vol.png",
                        NULL);
    vol->hover_down_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f hover_down_pos = {2220, 700};
    sfSprite_setTexture(vol->hover_down_spt, vol->hover_down_tex, sfFalse);
    sfSprite_setPosition(vol->hover_down_spt, hover_down_pos);
    sfSprite_setScale(vol->hover_down_spt, scale);
}

void print_down_vol(menu_t *menu, window_t *wnd)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);

    if ((mouse_pos.x >= box_size_x(wnd,
                    sfSprite_getGlobalBounds(menu->stg->vol->down_spt).left) &&
        mouse_pos.x <= (box_size_x(wnd,
                        sfSprite_getGlobalBounds(menu->stg->vol->down_spt).left) +
        box_size_x(wnd,
                    sfSprite_getGlobalBounds(menu->stg->vol->down_spt).width)))
        && (mouse_pos.y >= box_size_y(wnd,
                        sfSprite_getGlobalBounds(menu->stg->vol->down_spt).top) &&
        mouse_pos.y <= (box_size_y(wnd,
                        sfSprite_getGlobalBounds(menu->stg->vol->down_spt).top) +
        box_size_y(wnd,
                sfSprite_getGlobalBounds(menu->stg->vol->down_spt).height)))) {
            if (menu->button->enable_click == TRUE)
                sfRenderWindow_drawSprite(wnd->window,
                                        menu->stg->vol->down_click_spt, NULL);
            else
                sfRenderWindow_drawSprite(wnd->window,
                                        menu->stg->vol->hover_down_spt, NULL);
        }
        else
            sfRenderWindow_drawSprite(wnd->window,
                                        menu->stg->vol->down_spt, NULL);
}