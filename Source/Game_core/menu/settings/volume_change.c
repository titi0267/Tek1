/*
** EPITECH PROJECT, 2021
** change the volume by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** volume_change.c
*/

#include "../../../../include/defender.h"

void change_vol_up(volume_t *vol)
{
    if (vol->offset < 8) {
        vol->offset++;
        vol->vol_nbr.left = vol->offset *
        vol->vol_nbr.width;
    }
}

void change_vol_down(volume_t *vol)
{
    if (vol->offset > 0) {
        vol->offset--;
        vol->vol_nbr.left = vol->offset *
        vol->vol_nbr.width;
    }
}

void click_up_vol(volume_t *vol, window_t *wnd)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);

    if ((mouse_pos.x >= box_size_x(wnd,
                sfSprite_getGlobalBounds(vol->up_spt).left) &&
        mouse_pos.x <= (box_size_x(wnd,
                sfSprite_getGlobalBounds(vol->up_spt).left) +
        box_size_x(wnd,
            sfSprite_getGlobalBounds(vol->up_spt).width))) &&
        (mouse_pos.y >= box_size_y(wnd,
                sfSprite_getGlobalBounds(vol->up_spt).top) &&
        mouse_pos.y <= (box_size_y(wnd,
                sfSprite_getGlobalBounds(vol->up_spt).top) +
        box_size_y(wnd,
            sfSprite_getGlobalBounds(vol->up_spt).height))))
        change_vol_up(vol);
}

void click_down_vol(volume_t *vol, window_t *wnd)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);

    if ((mouse_pos.x >= box_size_x(wnd,
                sfSprite_getGlobalBounds(vol->down_spt).left) &&
        mouse_pos.x <= (box_size_x(wnd,
                sfSprite_getGlobalBounds(vol->down_spt).left) +
        box_size_x(wnd,
            sfSprite_getGlobalBounds(vol->down_spt).width))) &&
        (mouse_pos.y >= box_size_y(wnd,
                sfSprite_getGlobalBounds(vol->down_spt).top) &&
        mouse_pos.y <= (box_size_y(wnd,
                sfSprite_getGlobalBounds(vol->down_spt).top) +
        box_size_y(wnd,
            sfSprite_getGlobalBounds(vol->down_spt).height))))
        change_vol_down(vol);
}
