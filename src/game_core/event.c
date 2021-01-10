/*
** EPITECH PROJECT, 2020
** events by Timothy CONIEL
** File description:
** event.c
*/
#include "../../include/my.h"

void restart_click(sfEvent event, gather_t *gather)
{
    sfVector2i mouse_pos;

    mouse_pos = sfMouse_getPositionRenderWindow(gather->windo.window);
    if (event.type == sfEvtMouseButtonPressed) {
        if ((mouse_pos.x > 500 && mouse_pos.x < 745) && (mouse_pos.y > 400 &&
            mouse_pos.y < 540))
            gather->menu.change_button = 1;
    }
}

void space_pressed(sfEvent event, gather_t *gather)
{
    if (event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeySpace)) {
            gather->menu.game_starting = 1;
            gather->menu.start_count = 1;
            gather->bird.while_jump = 1;
            gather->bird.second_jump++;
            if (gather->menu.countdown <= 0 && gather->bird.death == 0)
                sfSound_play(gather->sound.jump);
        }
    }
}

void poll_event(sfRenderWindow *window, gather_t *gather)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        space_pressed(event, gather);
        restart_click(event, gather);
    }
}
