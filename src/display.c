/*
** EPITECH PROJECT, 2020
** display by Timothy CONIEL
** File description:
** display.c
*/
#include "../include/my.h"

void create_window(window_t *windo)
{
    windo->video_mode.width = 1350;
    windo->video_mode.height = 947.25f;
    windo->video_mode.bitsPerPixel = 32;
    windo->window = sfRenderWindow_create(windo->video_mode,
                                        "MyWindow",sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(windo->window, 55);
}

int keep_window_open(map_t *buff)
{
    gather_t gather;

    create_window(&gather.windo);
    if (call_init(&gather, buff) != 0)
        return (-1);
    while (sfRenderWindow_isOpen(gather.windo.window)) {
        sfRenderWindow_display(gather.windo.window);
        poll_event(gather.windo.window, &gather);
        update_time(&gather.time);
        if (gather.bird.death == 0) {
            updater(&gather);
            bird_action(&gather);
        } else
            death(&gather);
    }
    destroy(&gather);
    return (0);
}
