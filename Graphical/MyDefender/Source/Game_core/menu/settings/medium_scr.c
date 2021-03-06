/*
** EPITECH PROJECT, 2021
** medium screen by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** medium_scr.c
*/

#include "../../../../include/defender.h"

void medscr_button(settings_t *stg)
{
    stg->medscr_tex = sfTexture_createFromFile(
                            "Ressources/button/settings/size/1280-720.png",
                            NULL);
    stg->medscr_spt = sfSprite_create();
    sfVector2f scale = {0.25f, 0.25f};
    sfVector2f medscr_pos = {3320, 600};

    sfSprite_setTexture(stg->medscr_spt, stg->medscr_tex, sfFalse);
    sfSprite_setPosition(stg->medscr_spt, medscr_pos);
    sfSprite_setScale(stg->medscr_spt, scale);
}

void click_medscr_button(settings_t *stg)
{
    stg->click_medscr_tex = sfTexture_createFromFile(
                        "Ressources/button/settings/size/click_1280-720.png",
                            NULL);
    stg->click_medscr_spt = sfSprite_create();
    sfVector2f scale = {0.25f, 0.25f};
    sfVector2f click_medscr_pos = {3320, 600};

    sfSprite_setTexture(stg->click_medscr_spt, stg->click_medscr_tex, sfFalse);
    sfSprite_setPosition(stg->click_medscr_spt, click_medscr_pos);
    sfSprite_setScale(stg->click_medscr_spt, scale);
    stg->click_medscr = FALSE;
}

void hover_medscr_button(settings_t *stg)
{
    stg->hover_medscr_tex = sfTexture_createFromFile(
                        "Ressources/button/settings/size/hover_1280-720.png",
                            NULL);
    stg->hover_medscr_spt = sfSprite_create();
    sfVector2f scale = {0.25f, 0.25f};
    sfVector2f hover_medscr_pos = {3320, 600};

    sfSprite_setTexture(stg->hover_medscr_spt, stg->hover_medscr_tex, sfFalse);
    sfSprite_setPosition(stg->hover_medscr_spt, hover_medscr_pos);
    sfSprite_setScale(stg->hover_medscr_spt, scale);
}

void print_medscr(settings_t *stg, window_t *wnd, menu_t *menu)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);
    sfFloatRect medscr_spt = sfSprite_getGlobalBounds(stg->medscr_spt);

    if ((mouse_pos.x >= box_size_x(wnd, medscr_spt.left) && mouse_pos.x <=
        (box_size_x(wnd, medscr_spt.left) + box_size_x(wnd, medscr_spt.width)))
        && (mouse_pos.y >= box_size_y(wnd, medscr_spt.top) && mouse_pos.y <=
        (box_size_y(wnd, medscr_spt.top) + box_size_y(wnd,
        medscr_spt.height)))) {
            if (menu->button->enable_click == TRUE) {
                sfRenderWindow_drawSprite(wnd->window,
                                    stg->click_medscr_spt, NULL);
                stg->click_medscr = TRUE;
            } else
                sfRenderWindow_drawSprite(wnd->window,
                                        stg->hover_medscr_spt, NULL);
    } else
        sfRenderWindow_drawSprite(wnd->window, stg->medscr_spt, NULL);
    resize_wnd_med(menu, wnd);
}