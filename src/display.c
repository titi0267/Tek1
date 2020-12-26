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

    init_background(&back);
    bird_init(&bird);
    pipe_sprite(window, &enemy, buff);
    window = sfRenderWindow_create(video_mode, "MyWindow", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        poll_event(window);
        set_background(window, &back);
        bird_sprite(window, &bird);
        delta_time = sfClock_restart(clock).microseconds / 1000000.0;
        elapsed_time += delta_time;
        pos_update(window, &enemy);
        timer(delta_time, &back);
        enemy_speed(delta_time, buff, &bird, &enemy, window);
        birdrect_speed(delta_time, &bird);
    }
    sfSprite_destroy(enemy.my_pipe);
    sfTexture_destroy(enemy.pipe_tex);
    sfRenderWindow_destroy(window);
}
