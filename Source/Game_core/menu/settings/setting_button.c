/*
** EPITECH PROJECT, 2021
** settings button by TImothy CONIEL & Tristan HOURTOULLE
** File description:
** button.c
*/

#include "../../../../include/defender.h"

void hover_setting_but(button_t *button)
{
    button->hover_setting_tex = sfTexture_createFromFile(
                        "Ressources/My_defender/button/settings_on.png",
                        NULL);
    button->hover_setting_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f setting_pos = {1400, 800};

    sfSprite_setTexture(button->hover_setting_spt,
                        button->hover_setting_tex, sfFalse);
    sfSprite_setPosition(button->hover_setting_spt, setting_pos);
    sfSprite_setScale(button->hover_setting_spt, scale);
}

void click_setting_but(button_t *button, menu_t *menu)
{
    button->click_settings_text = sfTexture_createFromFile(
                        "Ressources/My_defender/button/settings_click.png",
                        NULL);
    button->click_setting_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f setting_pos = {1400, 800};

    sfSprite_setTexture(button->click_setting_spt,
                        button->click_settings_text, sfFalse);
    sfSprite_setPosition(button->click_setting_spt, setting_pos);
    sfSprite_setScale(button->click_setting_spt, scale);
    menu->click_on_stg = FALSE;
}

void hover_setting(button_t *button, window_t *wnd, menu_t *menu)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);

    if ((mouse_pos.x >= box_size_x(wnd,
                        sfSprite_getGlobalBounds(button->setting_spt).left) &&
        mouse_pos.x <= (box_size_x(wnd,
                        sfSprite_getGlobalBounds(button->setting_spt).left) +
        box_size_x(wnd, sfSprite_getGlobalBounds(button->setting_spt).width)))
        && (mouse_pos.y >= box_size_y(wnd,
                        sfSprite_getGlobalBounds(button->setting_spt).top) &&
        mouse_pos.y <= (box_size_y(wnd,
                        sfSprite_getGlobalBounds(button->setting_spt).top) +
        box_size_y(wnd,
        sfSprite_getGlobalBounds(button->setting_spt).height)))) {
            if (menu->click_on_stg == FALSE)
                sfRenderWindow_drawSprite(wnd->window,
                                    button->hover_setting_spt, NULL);
            if (menu->click_on_stg == TRUE)
                sfRenderWindow_drawSprite(wnd->window,
                                    menu->button->click_setting_spt, NULL);
        } else
            sfRenderWindow_drawSprite(wnd->window, button->setting_spt, NULL);
}

void button_setting(button_t *button, menu_t *menu)
{
    button->setting_tex = sfTexture_createFromFile(
                            "Ressources/My_defender/button/settings.png",
                            NULL);
    button->setting_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f setting_pos = {1400, 800};

    sfSprite_setTexture(button->setting_spt, button->setting_tex, sfFalse);
    sfSprite_setPosition(button->setting_spt, setting_pos);
    sfSprite_setScale(button->setting_spt, scale);
    menu->settings = FALSE;
}
