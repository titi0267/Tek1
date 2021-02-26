/*
** EPITECH PROJECT, 2021
** switch background by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** switch_bg.c
*/

#include "../../../../include/defender.h"

void click_settings(menu_t *menu, sfEvent event, window_t *wnd)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);

    if (event.type == sfEvtMouseButtonPressed) {
        if ((mouse_pos.x >= box_size_x(wnd,
                    sfSprite_getGlobalBounds(menu->button->setting_spt).left) &&
            mouse_pos.x <= (box_size_x(wnd,
                    sfSprite_getGlobalBounds(menu->button->setting_spt).left) +
            box_size_x(wnd,
                sfSprite_getGlobalBounds(menu->button->setting_spt).width))) &&
            (mouse_pos.y >= box_size_y(wnd,
                    sfSprite_getGlobalBounds(menu->button->setting_spt).top) &&
            mouse_pos.y <= (box_size_y(wnd,
                    sfSprite_getGlobalBounds(menu->button->setting_spt).top) +
            box_size_y(wnd,
                sfSprite_getGlobalBounds(menu->button->setting_spt).height))))
                menu->settings = TRUE;
    }
}

void switch_bg_next(menu_t *menu, sfVector2f global_pos)
{
    global_pos.x = sfSprite_getGlobalBounds(menu->name_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->name_spt).top;
    global_pos.x -= 20;
    sfSprite_setPosition(menu->name_spt, global_pos);
    global_pos.x = sfSprite_getGlobalBounds(menu->button->play_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->button->play_spt).top;
    global_pos.x -= 20;
    sfSprite_setPosition(menu->button->play_spt, global_pos);
    global_pos.x = sfSprite_getGlobalBounds(menu->button->setting_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->button->setting_spt).top;
    global_pos.x -= 20;
    sfSprite_setPosition(menu->button->setting_spt, global_pos);
    global_pos.x = sfSprite_getGlobalBounds(menu->stg->vol->vol_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->stg->vol->vol_spt).top;
    global_pos.x -= 20;
    sfSprite_setPosition(menu->stg->vol->vol_spt, global_pos);
    global_pos.x = sfSprite_getGlobalBounds(menu->stg->return_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->stg->return_spt).top;
    global_pos.x -= 20;
    sfSprite_setPosition(menu->stg->return_spt, global_pos);
}

void switch_side_setting(menu_t *menu, sfVector2f global_pos)
{
    global_pos.x = sfSprite_getGlobalBounds(menu->stg->medscr_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->stg->medscr_spt).top;
    global_pos.x -= 20;
    sfSprite_setPosition(menu->stg->medscr_spt, global_pos);
    global_pos.x = sfSprite_getGlobalBounds(menu->stg->fullscr_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->stg->fullscr_spt).top;
    global_pos.x -= 20;
    sfSprite_setPosition(menu->stg->fullscr_spt, global_pos);
    global_pos.x = sfSprite_getGlobalBounds(menu->bgd_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->bgd_spt).top;
    global_pos.x -= 20;
    sfSprite_setPosition(menu->bgd_spt, global_pos);
    global_pos.x = sfSprite_getGlobalBounds(menu->set_bg_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->set_bg_spt).top;
    global_pos.x -= 20;
    sfSprite_setPosition(menu->set_bg_spt, global_pos);
    global_pos.x = sfSprite_getGlobalBounds(menu->stg->hover_return_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->stg->hover_return_spt).top;
    global_pos.x -= 20;
    sfSprite_setPosition(menu->stg->hover_return_spt, global_pos);
    global_pos.x = sfSprite_getGlobalBounds(menu->stg->hover_fullscr_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->stg->hover_fullscr_spt).top;
    global_pos.x -= 20;
    sfSprite_setPosition(menu->stg->hover_fullscr_spt, global_pos);
    global_pos.x = sfSprite_getGlobalBounds(menu->stg->hover_medscr_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->stg->hover_medscr_spt).top;
    global_pos.x -= 20;
    sfSprite_setPosition(menu->stg->hover_medscr_spt, global_pos);
    global_pos.x = sfSprite_getGlobalBounds(menu->stg->vol->vol_nbr_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->stg->vol->vol_nbr_spt).top;
    global_pos.x -= 20;
    sfSprite_setPosition(menu->stg->vol->vol_nbr_spt, global_pos);
}

void switch_bg(menu_t *menu)
{
    sfVector2f global_pos;

    if (sfSprite_getGlobalBounds(menu->set_bg_spt).left > 0 &&
        menu->return_to_menu == FALSE) {
        switch_bg_next(menu, global_pos);
        switch_side_setting(menu, global_pos);
    } else if (sfSprite_getGlobalBounds(menu->bgd_spt).left < 0 &&
            menu->return_to_menu == TRUE) {
        return_bg_next(menu, global_pos);
        return_side_setting(menu, global_pos);
    }
    if (sfSprite_getGlobalBounds(menu->bgd_spt).left >= 0) {
        menu->settings = FALSE;
        menu->return_to_menu = FALSE;
    }
}

void draw_spt_setting(menu_t *menu, window_t *wnd)
{
    settings_spt(menu, wnd);
    switch_bg(menu);
    hover_return(menu->stg, wnd);
    hover_leave(menu->button, wnd);
    hover_fullscr(menu->stg, wnd);
    hover_medscr(menu->stg, wnd);
}
