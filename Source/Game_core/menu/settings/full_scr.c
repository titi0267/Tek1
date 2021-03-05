/*
** EPITECH PROJECT, 2021
** fulll screen by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** full_scr.c
*/

#include "../../../../include/defender.h"

void fullscr_button(settings_t *stg)
{
    stg->fullscr_tex = sfTexture_createFromFile(
                            "Ressources/My_defender/button/1920-1080.png",
                            NULL);
    stg->fullscr_spt = sfSprite_create();
    sfVector2f scale = {0.25f, 0.25f};
    sfVector2f fullscr_pos = {3320, 400};

    sfSprite_setTexture(stg->fullscr_spt, stg->fullscr_tex, sfFalse);
    sfSprite_setPosition(stg->fullscr_spt, fullscr_pos);
    sfSprite_setScale(stg->fullscr_spt, scale);
}

void click_fullscr_button(settings_t *stg)
{
    stg->click_fullscr_tex = sfTexture_createFromFile(
                            "Ressources/My_defender/button/click_1920-1080.png",
                            NULL);
    stg->click_fullscr_spt = sfSprite_create();
    sfVector2f scale = {0.25f, 0.25f};
    sfVector2f click_fullscr_pos = {3320, 400};

    sfSprite_setTexture(stg->click_fullscr_spt, stg->click_fullscr_tex, sfFalse);
    sfSprite_setPosition(stg->click_fullscr_spt, click_fullscr_pos);
    sfSprite_setScale(stg->click_fullscr_spt, scale);
}

void hover_fullscr_button(settings_t *stg)
{
    stg->hover_fullscr_tex = sfTexture_createFromFile(
                            "Ressources/My_defender/button/hover_1920-1080.png",
                            NULL);
    stg->hover_fullscr_spt = sfSprite_create();
    sfVector2f scale = {0.25f, 0.25f};
    sfVector2f hover_fullscr_pos = {3320, 400};

    sfSprite_setTexture(stg->hover_fullscr_spt, stg->hover_fullscr_tex, sfFalse);
    sfSprite_setPosition(stg->hover_fullscr_spt, hover_fullscr_pos);
    sfSprite_setScale(stg->hover_fullscr_spt, scale);
}

void print_fullscr(settings_t *stg, window_t *wnd, menu_t *menu)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);

    if ((mouse_pos.x >= box_size_x(wnd,
                        sfSprite_getGlobalBounds(stg->fullscr_spt).left) &&
        mouse_pos.x <= (box_size_x(wnd,
                        sfSprite_getGlobalBounds(stg->fullscr_spt).left) +
        box_size_x(wnd, sfSprite_getGlobalBounds(stg->fullscr_spt).width))) &&
        (mouse_pos.y >= box_size_y(wnd,
                        sfSprite_getGlobalBounds(stg->fullscr_spt).top) &&
        mouse_pos.y <= (box_size_y(wnd,
                        sfSprite_getGlobalBounds(stg->fullscr_spt).top) +
        box_size_y(wnd, sfSprite_getGlobalBounds(stg->fullscr_spt).height)))) {
            if (menu->button->enable_click == FALSE)
                sfRenderWindow_drawSprite(wnd->window,
                                        stg->hover_fullscr_spt, NULL);
            else
                sfRenderWindow_drawSprite(wnd->window,
                                        stg->click_fullscr_spt, NULL);
        } else
            sfRenderWindow_drawSprite(wnd->window, stg->fullscr_spt, NULL);
}
