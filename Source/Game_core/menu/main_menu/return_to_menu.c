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
                        "Ressources/My_defender/button/undo.png",
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
                        "Ressources/My_defender/button/undo_on.png",
                        NULL);
    stg->hover_return_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f hover_return_pos = {2020, 50};

    sfSprite_setTexture(stg->hover_return_spt, stg->hover_return_tex, sfFalse);
    sfSprite_setPosition(stg->hover_return_spt, hover_return_pos);
    sfSprite_setScale(stg->hover_return_spt, scale);
}

void hover_return(settings_t *stg, window_t *wnd)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);

    if ((mouse_pos.x >= box_size_x(wnd,
                        sfSprite_getGlobalBounds(stg->return_spt).left) &&
        mouse_pos.x <= (box_size_x(wnd,
                        sfSprite_getGlobalBounds(stg->return_spt).left) +
        box_size_x(wnd, sfSprite_getGlobalBounds(stg->return_spt).width))) &&
        (mouse_pos.y >= box_size_y(wnd,
                        sfSprite_getGlobalBounds(stg->return_spt).top) &&
        mouse_pos.y <= (box_size_y(wnd,
                        sfSprite_getGlobalBounds(stg->return_spt).top) +
        box_size_y(wnd, sfSprite_getGlobalBounds(stg->return_spt).height))))
            sfRenderWindow_drawSprite(wnd->window,
                                    stg->hover_return_spt, NULL);
        else
            sfRenderWindow_drawSprite(wnd->window, stg->return_spt, NULL);
}

void return_to_menu(menu_t *menu, settings_t *stg, sfEvent event, window_t *wnd)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);

    if (event.type == sfEvtMouseButtonPressed) {
        if ((mouse_pos.x >= box_size_x(wnd,
                        sfSprite_getGlobalBounds(stg->return_spt).left) &&
            mouse_pos.x <= (box_size_x(wnd,
                            sfSprite_getGlobalBounds(stg->return_spt).left) +
            box_size_x(wnd, sfSprite_getGlobalBounds(stg->return_spt).width)))
            && (mouse_pos.y >= box_size_y(wnd,
                            sfSprite_getGlobalBounds(stg->return_spt).top) &&
            mouse_pos.y <= (box_size_y(wnd,
                            sfSprite_getGlobalBounds(stg->return_spt).top) +
            box_size_y(wnd,
                        sfSprite_getGlobalBounds(stg->return_spt).height))))
                menu->return_to_menu = TRUE;
    }
}