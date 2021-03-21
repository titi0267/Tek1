/*
** EPITECH PROJECT, 2021
** play again by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** play_again.c
*/

#include "../../../../include/defender.h"

void play_again_but(pause_t *pause, menu_t *menu)
{
    sfVector2f scale = {1, 1};
    sfVector2f pos = {2500, 500};

    pause->play_spt = sfSprite_copy(menu->button->play_spt);
    pause->play_click_spt = sfSprite_copy(menu->button->click_play_spt);
    pause->play_hover_spt = sfSprite_copy(menu->button->hover_play_spt);
    sfSprite_setPosition(pause->play_spt, pos);
    sfSprite_setScale(pause->play_spt, scale);
    sfSprite_setPosition(pause->play_click_spt, pos);
    sfSprite_setScale(pause->play_click_spt, scale);
    sfSprite_setPosition(pause->play_hover_spt, pos);
    sfSprite_setScale(pause->play_hover_spt, scale);
}

void draw_restart(pause_t *pause, menu_t *menu, window_t *wnd)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);
    sfFloatRect play = sfSprite_getGlobalBounds(pause->play_spt);

    if ((mouse_pos.x >= box_size_x(wnd, play.left) && mouse_pos.x <=
        (box_size_x(wnd, play.left) + box_size_x(wnd, play.width))) &&
        (mouse_pos.y >= box_size_y(wnd, play.top) && mouse_pos.y <=
        (box_size_y(wnd, play.top) + box_size_y(wnd, play.height)))) {
        if (menu->button->enable_click == TRUE) {
            sfRenderWindow_drawSprite(wnd->window, pause->play_click_spt, NULL);
            menu->game_bgd = TRUE;
            menu->return_to_menu = TRUE;
            menu->pause_on = TRUE;
            menu->menu_bg = FALSE;
            my_printf("return = %i\n", menu->return_to_menu);
        } else
            sfRenderWindow_drawSprite(wnd->window,
                                    pause->play_hover_spt, NULL);
        } else
            sfRenderWindow_drawSprite(wnd->window, pause->play_spt, NULL);
}
