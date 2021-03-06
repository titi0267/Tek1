/*
** EPITECH PROJECT, 2021
** return to main menu by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** return_to_menu.c
*/

#include "../../../../include/defender.h"

void back_to_menu_spt(menu_t *menu)
{
    menu->stg->return_tex = sfTexture_createFromFile(
                    "Ressources/button/settings/return/return.png",
                    NULL);
    menu->stg->return_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f return_pos = {2020, 50};

    sfSprite_setTexture(menu->stg->return_spt, menu->stg->return_tex, sfFalse);
    sfSprite_setPosition(menu->stg->return_spt, return_pos);
    sfSprite_setScale(menu->stg->return_spt, scale);
    menu->return_to_menu = FALSE;
}

void hover_back_to_menu_spt(settings_t *stg)
{
    stg->hover_return_tex = sfTexture_createFromFile(
                        "Ressources/button/settings/return/hover_return.png",
                        NULL);
    stg->hover_return_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f hover_return_pos = {2020, 50};

    sfSprite_setTexture(stg->hover_return_spt, stg->hover_return_tex, sfFalse);
    sfSprite_setPosition(stg->hover_return_spt, hover_return_pos);
    sfSprite_setScale(stg->hover_return_spt, scale);
}

void click_back_to_menu_spt(settings_t *stg)
{
    stg->click_return_tex = sfTexture_createFromFile(
                        "Ressources/button/settings/return/hover_return.png",
                        NULL);
    stg->click_return_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f click_return_pos = {2020, 50};

    sfSprite_setTexture(stg->click_return_spt, stg->click_return_tex, sfFalse);
    sfSprite_setPosition(stg->click_return_spt, click_return_pos);
    sfSprite_setScale(stg->click_return_spt, scale);
}

void draw_return(settings_t *stg, menu_t *menu, window_t *wnd)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);
    sfFloatRect return_spt = sfSprite_getGlobalBounds(stg->return_spt);

    if ((mouse_pos.x >= box_size_x(wnd, return_spt.left) && mouse_pos.x <=
        (box_size_x(wnd, return_spt.left) + box_size_x(wnd, return_spt.width)))
        && (mouse_pos.y >= box_size_y(wnd, return_spt.top) && mouse_pos.y <=
        (box_size_y(wnd, return_spt.top) +
        box_size_y(wnd, return_spt.height)))) {
        if (menu->button->enable_click == TRUE) {
            sfRenderWindow_drawSprite(wnd->window,
                                    stg->click_return_spt, NULL);
            menu->return_to_menu = TRUE;
            menu->menu_bg = FALSE;
            menu->settings = FALSE;
            menu->go_to_stg = FALSE;
        } else
            sfRenderWindow_drawSprite(wnd->window,
                                    stg->hover_return_spt, NULL);
    } else
        sfRenderWindow_drawSprite(wnd->window, stg->return_spt, NULL);
}
