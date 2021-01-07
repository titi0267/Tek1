/*
** EPITECH PROJECT, 2020
** events by Timothy CONIEL
** File description:
** event.c
*/
#include "../include/my.h"

void space_pressed(sfEvent event, gather_t *gather)
{
    if (event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeySpace)) {
            gather->bird.while_jump = 1;
            gather->bird.second_jump++;
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
    }
}
