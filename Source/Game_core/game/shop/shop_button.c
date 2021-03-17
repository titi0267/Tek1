/*
** EPITECH PROJECT, 2021
** shop button by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** shop button
*/

#include "../../../../include/defender.h"

void shop_button(shop_t *shop, menu_t *menu)
{
    shop->shop_tex = sfTexture_createFromFile(
                        "Ressources/button/settings/size/1920-1080.png",
                        NULL);
    shop->shop_spt = sfSprite_create();
    sfVector2f scale = {0.25f, 0.25f};
    sfVector2f shop_pos = {1700, 100};

    sfSprite_setTexture(shop->shop_spt, shop->shop_tex, sfFalse);
    sfSprite_setPosition(shop->shop_spt, shop_pos);
    sfSprite_setScale(shop->shop_spt, scale);
    menu->shop_bgd = FALSE;
    menu->shop_to_gm = FALSE;
    menu->shop_release = FALSE;
}

void shop_disappear(shop_t *shop, menu_t *menu, window_t *wnd)
{
    if (menu->button->enable_click == FALSE) {
        sfRenderWindow_drawSprite(wnd->window, shop->shop_spt, NULL);
        if (menu->shop_bgd == TRUE)
            menu->shop_release = TRUE;
        else
            menu->shop_release = FALSE;
    } else {
        sfRenderWindow_drawSprite(wnd->window, shop->shop_spt, NULL);
        if (menu->shop_bgd == TRUE)
            menu->shop_to_gm = TRUE;
        menu->game_bgd = TRUE;
        menu->shop_bgd = TRUE;
        if (menu->shop_to_gm == TRUE && menu->shop_release == TRUE)
            menu->shop_bgd = FALSE;
    }
}

void click_shop(shop_t *shop, window_t *wnd, menu_t *menu)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);
    sfFloatRect shop_pos = sfSprite_getGlobalBounds(shop->shop_spt);

    if ((mouse_pos.x >= box_size_x(wnd, shop_pos.left) && mouse_pos.x <=
        (box_size_x(wnd, shop_pos.left) + box_size_x(wnd, shop_pos.width)))
        && (mouse_pos.y >= box_size_y(wnd, shop_pos.top) && mouse_pos.y <=
        (box_size_y(wnd, shop_pos.top) + box_size_y(wnd, shop_pos.height)))) {
            shop_disappear(shop, menu, wnd);
    } else
        sfRenderWindow_drawSprite(wnd->window,
                                shop->shop_spt, NULL);
}

void get_spt_mouse(tower_t *tower, window_t *wnd)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(wnd->window);

    tower->mouse_pos = sfRenderWindow_mapPixelToCoords(wnd->window, mouse,
                                                    NULL);
    tower->mouse_pos.x -= sfSprite_getGlobalBounds(
                                tower->def_list[tower->wich_defense]).width / 2;
    tower->mouse_pos.y -= sfSprite_getGlobalBounds(
                            tower->def_list[tower->wich_defense]).height / 2;
    sfSprite_setPosition(
                        tower->def_list[tower->wich_defense], tower->mouse_pos);
    sfRenderWindow_drawSprite(wnd->window, tower->def_list[tower->wich_defense],
                            NULL);
    sfRenderWindow_setMouseCursorVisible(wnd->window, FALSE);
}
