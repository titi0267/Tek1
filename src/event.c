/*
** EPITECH PROJECT, 2020
** events by Timothy CONIEL
** File description:
** event.c
*/
#include "../include/my.h"

void space_pressed(sfEvent event, player_t *bird)
{
    if (event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeySpace)) {
            bird->while_jump = 1;
            bird->second_jump++;
        }
    }
}

void poll_event(sfRenderWindow *window, player_t *bird)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        space_pressed(event, bird);
    }
}
