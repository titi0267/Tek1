/*
** EPITECH PROJECT, 2020
** csfml
** File description:
** windo_disp
*/
#include "../include/my.h"

void poll_event(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void keep_window_open(void)
{
    sfRenderWindow *window;
    background_t back;
    sfVideoMode video_mode = {1350, 947.25f, 32};
    sfClock *clock = sfClock_create();
    float elapsed_time = 0;
    float delta_time = 0;

    init_background(&back);
    window = sfRenderWindow_create(video_mode, "MyWindow", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        poll_event(window);
        set_background(window, &back);
        delta_time = sfClock_restart(clock).microseconds / 1000000.0;
        elapsed_time += delta_time;
        timer(delta_time, &back);
    }
    sfRenderWindow_destroy(window);
}
