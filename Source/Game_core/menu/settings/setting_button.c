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
                        "Ressources/button/menu/setting/hover_settings.png",
                        NULL);
    button->hover_setting_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f setting_pos = {1400, 800};

    sfSprite_setTexture(button->hover_setting_spt,
                        button->hover_setting_tex, sfFalse);
    sfSprite_setPosition(button->hover_setting_spt, setting_pos);
    sfSprite_setScale(button->hover_setting_spt, scale);
}

void click_setting_but(button_t *button)
{
    button->click_settings_tex = sfTexture_createFromFile(
                        "Ressources/button/menu/setting/click_settings.png",
                        NULL);
    button->click_setting_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f setting_pos = {1400, 800};

    sfSprite_setTexture(button->click_setting_spt,
                        button->click_settings_tex, sfFalse);
    sfSprite_setPosition(button->click_setting_spt, setting_pos);
    sfSprite_setScale(button->click_setting_spt, scale);
}

void draw_setting_btn(menu_t *menu, window_t *wnd)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);
    sfFloatRect setting = sfSprite_getGlobalBounds(menu->button->setting_spt);

    if ((mouse_pos.x >= box_size_x(wnd, setting.left) && mouse_pos.x <=
        (box_size_x(wnd, setting.left) + box_size_x(wnd, setting.width)))
        && (mouse_pos.y >= box_size_y(wnd, setting.top) && mouse_pos.y <=
        (box_size_y(wnd, setting.top) + box_size_y(wnd, setting.height)))) {
            if (menu->button->enable_click == FALSE)
                sfRenderWindow_drawSprite(wnd->window,
                                    menu->button->hover_setting_spt, NULL);
            else {
                sfRenderWindow_drawSprite(wnd->window,
                                        menu->button->click_setting_spt, NULL);
                menu->go_to_stg = TRUE;
                menu->menu_bg = FALSE;
                menu->settings = FALSE;
                menu->return_to_menu = FALSE;
            }
        } else
            sfRenderWindow_drawSprite(wnd->window,
                                    menu->button->setting_spt, NULL);
}

void button_setting(button_t *button, menu_t *menu)
{
    button->setting_tex = sfTexture_createFromFile(
                            "Ressources/button/menu/setting/settings.png",
                            NULL);
    button->setting_spt = sfSprite_create();
    sfVector2f scale = {1, 1};
    sfVector2f setting_pos = {1400, 800};

    sfSprite_setTexture(button->setting_spt, button->setting_tex, sfFalse);
    sfSprite_setPosition(button->setting_spt, setting_pos);
    sfSprite_setScale(button->setting_spt, scale);
    menu->settings = FALSE;
    menu->go_to_stg = FALSE;
}
