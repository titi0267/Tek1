/*
** EPITECH PROJECT, 2020
** csfml
** File description:
** windo_disp
*/
#include "../include/my.h"

/*void stop_game(enemy_t *enemy, player_t *bird)
{
    if (bird->position.y <= enemy->collision[0] || bird->position.y >= enemy->collision[1])
        bird->death = 1;
}
*/
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
    bird.while_jump = 0;
    bird.second_jump = 0;
    bird.rotation = 0;
    bird.stop_jump = 0;
    bird.fall_fast = 1;

    window = sfRenderWindow_create(video_mode, "MyWindow", sfResize | sfClose, NULL);
    bird_sprite(&bird);
    pipe_sprite(&enemy, buff);
    bottom(&back);
    background(&back);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        delta_time = sfClock_restart(clock).microseconds / 1000000.0;
        elapsed_time += delta_time;
        poll_event(window, &bird);
        updater(window, &enemy, &back, &bird);
        birdrect_speed(delta_time, &bird);
        if (bird.while_jump == 0)
            fall(&bird, delta_time);
        jump(&bird);
    }
    destroy_sprite(&back, &enemy, &bird);
    sfRenderWindow_destroy(window);
}
