/*
** EPITECH PROJECT, 2021
** volume arrays by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** volume_arrays.c
*/

#include "../../../../include/defender.h"

void volume_up_spt(volume_t *vol)
{
    vol->up_tex = sfTexture_createFromFile(
                        "Ressources/button/settings/volume/up_vol.png",
                        NULL);
    vol->up_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f up_pos = {2220, 400};

    sfSprite_setTexture(vol->up_spt, vol->up_tex, sfFalse);
    sfSprite_setPosition(vol->up_spt, up_pos);
    sfSprite_setScale(vol->up_spt, scale);
}

void up_click_spt(volume_t *vol)
{
    vol->up_click_tex = sfTexture_createFromFile(
                        "Ressources/button/settings/volume/up_vol_click.png",
                        NULL);
    vol->up_click_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f up_click_pos = {2220, 400};

    sfSprite_setTexture(vol->up_click_spt, vol->up_click_tex, sfFalse);
    sfSprite_setPosition(vol->up_click_spt, up_click_pos);
    sfSprite_setScale(vol->up_click_spt, scale);
    vol->click_up = FALSE;
}

void hover_up_spt(volume_t *vol)
{
    vol->hover_up_tex = sfTexture_createFromFile(
                        "Ressources/button/settings/volume/hover_up_vol.png",
                        NULL);
    vol->hover_up_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f hover_up_pos = {2220, 400};

    sfSprite_setTexture(vol->hover_up_spt, vol->hover_up_tex, sfFalse);
    sfSprite_setPosition(vol->hover_up_spt, hover_up_pos);
    sfSprite_setScale(vol->hover_up_spt, scale);
}

void print_up_vol(menu_t *menu, window_t *wnd)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);
    sfFloatRect up_spt = sfSprite_getGlobalBounds(menu->stg->vol->up_spt);

    if ((mouse_pos.x >= box_size_x(wnd, up_spt.left) && mouse_pos.x <=
        (box_size_x(wnd, up_spt.left) + box_size_x(wnd, up_spt.width))) &&
        (mouse_pos.y >= box_size_y(wnd, up_spt.top) && mouse_pos.y <=
        (box_size_y(wnd, up_spt.top) + box_size_y(wnd, up_spt.height)))) {
        if (menu->button->enable_click == TRUE) {
            sfRenderWindow_drawSprite(wnd->window,
                                    menu->stg->vol->up_click_spt, NULL);
            menu->stg->vol->click_up = TRUE;
        } else
            sfRenderWindow_drawSprite(wnd->window,
                                    menu->stg->vol->hover_up_spt, NULL);
    } else
        sfRenderWindow_drawSprite(wnd->window, menu->stg->vol->up_spt, NULL);
    change_vol_up(menu);
}
