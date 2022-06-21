/*
** EPITECH PROJECT, 2021
** economic center by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** eco_center.c
*/

#include "../../../../include/defender.h"

void eco_center_spt(tower_t *tower)
{
    tower->eco_center_tex = sfTexture_createFromFile(
                        "Ressources/tower/eco_center.png",
                        NULL);
    tower->eco_center_spt = sfSprite_create();
    sfVector2f scale = {2.4f, 2.4f};
    sfVector2f eco_center_pos = {1500, 700};

    sfSprite_setTexture(tower->eco_center_spt, tower->eco_center_tex, sfFalse);
    sfSprite_setPosition(tower->eco_center_spt, eco_center_pos);
    sfSprite_setScale(tower->eco_center_spt, scale);
    tower->eco_placed = FALSE;
}

void click_eco_center(window_t *wnd, menu_t *menu, tower_t *tower)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);
    sfFloatRect eco_pos = sfSprite_getGlobalBounds(tower->eco_center_spt);

    if ((mouse_pos.x >= box_size_x(wnd, eco_pos.left) && mouse_pos.x <=
        (box_size_x(wnd, eco_pos.left) + box_size_x(wnd, eco_pos.width)))
        && (mouse_pos.y >= box_size_y(wnd, eco_pos.top) && mouse_pos.y <=
        (box_size_y(wnd, eco_pos.top) + box_size_y(wnd, eco_pos.height)))) {
        if (menu->button->enable_click == TRUE) {
            tower->tower_click = TRUE;
            tower->wich_defense = eco_center;
        }
        else {
            sfRenderWindow_drawSprite(wnd->window,
                                    tower->eco_center_spt, NULL);
        }
    } else
        sfRenderWindow_drawSprite(wnd->window,
                                    tower->eco_center_spt, NULL);
}
