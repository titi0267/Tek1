/*
** EPITECH PROJECT, 2021
** tower by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** tower_spt.c
*/

#include "../../../../include/defender.h"

void ice_tower_spt(tower_t *tower)
{
    tower->ice_tower_tex = sfTexture_createFromFile(
                        "Ressources/tower/ice_tower.png",
                        NULL);
    tower->ice_tower_spt = sfSprite_create();
    sfVector2f scale = {2, 2};
    sfVector2f ice_tower_pos = {1500, 100};

    sfSprite_setTexture(tower->ice_tower_spt, tower->ice_tower_tex, sfFalse);
    sfSprite_setPosition(tower->ice_tower_spt, ice_tower_pos);
    sfSprite_setScale(tower->ice_tower_spt, scale);
    tower->tower_click = FALSE;
    tower->tower_release = FALSE;
}

void click_ice_tower(window_t *wnd, menu_t *menu, tower_t *tower)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);
    sfFloatRect ice_pos = sfSprite_getGlobalBounds(tower->ice_tower_spt);

    if ((mouse_pos.x >= box_size_x(wnd, ice_pos.left) && mouse_pos.x <=
        (box_size_x(wnd, ice_pos.left) + box_size_x(wnd, ice_pos.width)))
        && (mouse_pos.y >= box_size_y(wnd, ice_pos.top) && mouse_pos.y <=
        (box_size_y(wnd, ice_pos.top) + box_size_y(wnd, ice_pos.height)))) {
        if (menu->button->enable_click == TRUE) {
            tower->tower_click = TRUE;
            tower->wich_defense = 0;
        }
        else {
            sfRenderWindow_drawSprite(wnd->window,
                                    tower->ice_tower_spt, NULL);
        }
    } else
        sfRenderWindow_drawSprite(wnd->window,
                                    tower->ice_tower_spt, NULL);
}
