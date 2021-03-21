/*
** EPITECH PROJECT, 2021
** archer by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** arrow_tower.c
*/

#include "../../../../include/defender.h"

void archer_spt(tower_t *tower)
{
    tower->arrow_tower_tex = sfTexture_createFromFile(
                        "Ressources/tower/archer_tower.png",
                        NULL);
    tower->arrow_tower_spt = sfSprite_create();
    sfVector2f scale = {2, 2};
    sfVector2f arrow_tower_pos = {1500, 300};

    sfSprite_setTexture(tower->arrow_tower_spt, tower->arrow_tower_tex,
                        sfFalse);
    sfSprite_setPosition(tower->arrow_tower_spt, arrow_tower_pos);
    sfSprite_setScale(tower->arrow_tower_spt, scale);
}

void click_arrow_tower(window_t *wnd, menu_t *menu, tower_t *tower)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);
    sfFloatRect arrow_pos = sfSprite_getGlobalBounds(tower->arrow_tower_spt);

    if ((mouse_pos.x >= box_size_x(wnd, arrow_pos.left) && mouse_pos.x <=
        (box_size_x(wnd, arrow_pos.left) + box_size_x(wnd, arrow_pos.width)))
        && (mouse_pos.y >= box_size_y(wnd, arrow_pos.top) && mouse_pos.y <=
        (box_size_y(wnd, arrow_pos.top) +
        box_size_y(wnd, arrow_pos.height)))) {
        if (menu->button->enable_click == TRUE) {
            tower->tower_click = TRUE;
            tower->wich_defense = arrow_tower;
        } else {
            sfRenderWindow_drawSprite(wnd->window,
                                    tower->arrow_tower_spt, NULL);
        }
    } else
        sfRenderWindow_drawSprite(wnd->window,
                                    tower->arrow_tower_spt, NULL);
}