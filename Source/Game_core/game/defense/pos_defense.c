/*
** EPITECH PROJECT, 2021
** defense position by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** pos_defense.c
*/

#include "../../../../include/defender.h"

void place_def(game_t *game, menu_t *menu, window_t *wnd)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);
    sfFloatRect shop_pos = sfSprite_getGlobalBounds(game->tower->pt);

    if ((mouse_pos.x >= box_size_x(wnd, shop_pos.left) && mouse_pos.x <=
        (box_size_x(wnd, shop_pos.left) + box_size_x(wnd, shop_pos.width)))
        && (mouse_pos.y >= box_size_y(wnd, shop_pos.top) && mouse_pos.y <=
        (box_size_y(wnd, shop_pos.top) + box_size_y(wnd, shop_pos.height)))) {
            shop_disappear(shop, menu, wnd);
    } else
        sfRenderWindow_drawSprite(wnd->window,
                                shop->shop_spt, NULL);
}
