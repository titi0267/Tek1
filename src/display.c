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

void keep_window_open(map_t *buff)
{
    sfRenderWindow *window;
    background_t back;
    player_t bird;
    enemy_t enemy;
    sfVideoMode video_mode = {1350, 947.25f, 32};
    sfClock *clock = sfClock_create();
    float elapsed_time = 0;
    float delta_time = 0;

    window = sfRenderWindow_create(video_mode, "MyWindow", sfResize | sfClose, NULL);
    bird_init(&bird);
    pipe_sprite(&enemy, buff);
    bottom(&back);
    background(&back);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        poll_event(window);
        delta_time = sfClock_restart(clock).microseconds / 1000000.0;
        elapsed_time += delta_time;
        background_update(window, &back);
        bottom_update(window, &back);
        pipe_update(window, &enemy);
        bird_sprite(window, &bird);
        birdrect_speed(delta_time, &bird);
    }
    destroy_sprite(&back, &enemy);
    sfRenderWindow_destroy(window);
}
