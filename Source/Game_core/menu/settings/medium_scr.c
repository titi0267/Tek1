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
                            "Ressources/My_defender/button/1280x720.png",
                            NULL);
    stg->medscr_spt = sfSprite_create();
    sfVector2f scale = {0.25f, 0.25f};
    sfVector2f medscr_pos = {3320, 700};

    sfSprite_setTexture(stg->medscr_spt, stg->medscr_tex, sfFalse);
    sfSprite_setPosition(stg->medscr_spt, medscr_pos);
    sfSprite_setScale(stg->medscr_spt, scale);
}

void hover_medscr_button(settings_t *stg)
{
    stg->hover_medscr_tex = sfTexture_createFromFile(
                            "Ressources/My_defender/button/1280x720_on.png",
                            NULL);
    stg->hover_medscr_spt = sfSprite_create();
    sfVector2f scale = {0.25f, 0.25f};
    sfVector2f hover_medscr_pos = {3320, 700};

    sfSprite_setTexture(stg->hover_medscr_spt, stg->hover_medscr_tex, sfFalse);
    sfSprite_setPosition(stg->hover_medscr_spt, hover_medscr_pos);
    sfSprite_setScale(stg->hover_medscr_spt, scale);
}

void hover_medscr(settings_t *stg, window_t *wnd)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);

    if ((mouse_pos.x >= box_size_x(wnd,
                        sfSprite_getGlobalBounds(stg->medscr_spt).left) &&
        mouse_pos.x <= (box_size_x(wnd,
                        sfSprite_getGlobalBounds(stg->medscr_spt).left) +
        box_size_x(wnd, sfSprite_getGlobalBounds(stg->medscr_spt).width))) &&
        (mouse_pos.y >= box_size_y(wnd,
                        sfSprite_getGlobalBounds(stg->medscr_spt).top) &&
        mouse_pos.y <= (box_size_y(wnd,
                        sfSprite_getGlobalBounds(stg->medscr_spt).top) +
        box_size_y(wnd, sfSprite_getGlobalBounds(stg->medscr_spt).height))))
            sfRenderWindow_drawSprite(wnd->window,
                                    stg->hover_medscr_spt, NULL);
        else
            sfRenderWindow_drawSprite(wnd->window, stg->medscr_spt, NULL);
}