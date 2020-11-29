/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-timothe.coniel
** File description:
** clock
*/
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my_struct.h"
#include "../include/my.h"

int click(sfRenderWindow *window, sfEvent *event, duck_t *pos)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    if (event->type == sfEvtMouseButtonReleased) {
        if (mouse_pos.x >= pos->position.x && mouse_pos.x <= (pos->position.x + pos->rect.width)
            && mouse_pos.y >= pos->position.y && mouse_pos.y <= (pos->position.y + pos->rect.height)) {
            return (2);
            }
    }
    return (0);
}

void poll_event(sfRenderWindow *window, duck_t *pos)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        restart(window, &event, pos);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}