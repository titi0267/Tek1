/*
** EPITECH PROJECT, 2021
** switch background to initial menu by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** switch_return_menu.c
*/

#include "../../../../include/defender.h"

void settings_spt(menu_t *menu, window_t *wnd)
{
    sfRenderWindow_drawSprite(wnd->window, menu->set_bg_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->bgd_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->name_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->button->play_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->button->setting_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->stg->medscr_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->stg->fullscr_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->stg->vol->vol_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, menu->stg->return_spt, NULL);
    sfSprite_setTextureRect(menu->stg->vol->vol_nbr_spt, menu->stg->vol->vol_nbr);
    sfRenderWindow_drawSprite(wnd->window, menu->stg->vol->vol_nbr_spt, NULL);
}

void return_bg_3(menu_t *menu, sfVector2f global_pos)
{
    global_pos.x = sfSprite_getGlobalBounds(menu->stg->vol->vol_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->stg->vol->vol_spt).top;
    global_pos.x += 20;
    sfSprite_setPosition(menu->stg->vol->vol_spt, global_pos);
    global_pos.x = sfSprite_getGlobalBounds(menu->stg->return_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->stg->return_spt).top;
    global_pos.x += 20;
    sfSprite_setPosition(menu->stg->return_spt, global_pos);
    global_pos.x = sfSprite_getGlobalBounds(menu->stg->hover_fullscr_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->stg->hover_fullscr_spt).top;
    global_pos.x += 20;
    sfSprite_setPosition(menu->stg->hover_fullscr_spt, global_pos);
    global_pos.x = sfSprite_getGlobalBounds(menu->stg->hover_medscr_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->stg->hover_medscr_spt).top;
    global_pos.x += 20;
    sfSprite_setPosition(menu->stg->hover_medscr_spt, global_pos);
    global_pos.x = sfSprite_getGlobalBounds(menu->stg->hover_return_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->stg->hover_return_spt).top;
    global_pos.x += 20;
    sfSprite_setPosition(menu->stg->hover_return_spt, global_pos);
}

void return_bg_next(menu_t *menu, sfVector2f global_pos)
{
    global_pos.x = sfSprite_getGlobalBounds(menu->name_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->name_spt).top;
    global_pos.x += 20;
    sfSprite_setPosition(menu->name_spt, global_pos);
    global_pos.x = sfSprite_getGlobalBounds(menu->button->play_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->button->play_spt).top;
    global_pos.x += 20;
    sfSprite_setPosition(menu->button->play_spt, global_pos);
    global_pos.x = sfSprite_getGlobalBounds(menu->button->setting_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->button->setting_spt).top;
    global_pos.x += 20;
    sfSprite_setPosition(menu->button->setting_spt, global_pos);
    global_pos.x = sfSprite_getGlobalBounds(menu->set_bg_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->set_bg_spt).top;
    global_pos.x += 20;
    sfSprite_setPosition(menu->set_bg_spt, global_pos);
    global_pos.x = sfSprite_getGlobalBounds(menu->stg->vol->vol_nbr_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->stg->vol->vol_nbr_spt).top;
    global_pos.x += 20;
    sfSprite_setPosition(menu->stg->vol->vol_nbr_spt, global_pos);
    return_bg_3(menu, global_pos);
}

void return_side_setting(menu_t *menu, sfVector2f global_pos)
{
    global_pos.x = sfSprite_getGlobalBounds(menu->stg->medscr_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->stg->medscr_spt).top;
    global_pos.x += 20;
    sfSprite_setPosition(menu->stg->medscr_spt, global_pos);
    global_pos.x = sfSprite_getGlobalBounds(menu->stg->fullscr_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->stg->fullscr_spt).top;
    global_pos.x += 20;
    sfSprite_setPosition(menu->stg->fullscr_spt, global_pos);
    global_pos.x = sfSprite_getGlobalBounds(menu->bgd_spt).left;
    global_pos.y = sfSprite_getGlobalBounds(menu->bgd_spt).top;
    global_pos.x += 20;
    sfSprite_setPosition(menu->bgd_spt, global_pos);
}