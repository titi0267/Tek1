/*
** EPITECH PROJECT, 2021
** wizzard tower by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** wizzard_tower.c
*/

#include "../../../../include/defender.h"

void wizzard_spt(tower_t *tower)
{
    tower->wiz_tower_tex = sfTexture_createFromFile(
                        "Ressources/tower/wiz_tower.png",
                        NULL);
    tower->wiz_tower_spt = sfSprite_create();
    sfVector2f scale = {2, 2};
    sfVector2f wiz_tower_pos = {1500, 500};

    sfSprite_setTexture(tower->wiz_tower_spt, tower->wiz_tower_tex, sfFalse);
    sfSprite_setPosition(tower->wiz_tower_spt, wiz_tower_pos);
    sfSprite_setScale(tower->wiz_tower_spt, scale);
}

void click_wiz_tower(window_t *wnd, menu_t *menu, tower_t *tower)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);
    sfFloatRect wiz_pos = sfSprite_getGlobalBounds(tower->wiz_tower_spt);

    if ((mouse_pos.x >= box_size_x(wnd, wiz_pos.left) && mouse_pos.x <=
        (box_size_x(wnd, wiz_pos.left) + box_size_x(wnd, wiz_pos.width)))
        && (mouse_pos.y >= box_size_y(wnd, wiz_pos.top) && mouse_pos.y <=
        (box_size_y(wnd, wiz_pos.top) + box_size_y(wnd, wiz_pos.height)))) {
        if (menu->button->enable_click == TRUE) {
            tower->tower_click = TRUE;
            tower->wich_defense = 2;
        } else {
            sfRenderWindow_drawSprite(wnd->window,
                                    tower->wiz_tower_spt, NULL);
        }
    } else
        sfRenderWindow_drawSprite(wnd->window,
                                    tower->wiz_tower_spt, NULL);
}
