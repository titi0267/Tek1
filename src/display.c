/*
** EPITECH PROJECT, 2020
** display by Timothy CONIEL
** File description:
** display.c
*/
#include "../include/my.h"

void keep_window_open(map_t *buff)
{
    sfRenderWindow *window;
    gather_t gather;
    sfVideoMode video_mode = {1350, 947.25f, 32};
    sfClock *clock = sfClock_create();
    float elapsed_time = 0;
    float delta_time = 0;
    gather.score.amount = 0;
    gather.score.increase_score = 0;

    window = sfRenderWindow_create(video_mode, "MyWindow", sfResize | sfClose, NULL);
    //gather.sound.music = sfMusic_createFromFile("png/coin_music.ogg");
    //gather.sound.coin = sfSound_create();
    //gather.sound.coin_buf = sfSoundBuffer_createFromFile("png/coin_sound.ogg");
    //sfSound_setBuffer(gather.sound.coin, gather.sound.coin_buf);
    bird_sprite(&gather.bird);
    create_sound(&gather.sound);
    pipe_sprite(&gather.enemy, buff, &gather.bird);
    bottom(&gather.back);
    background(&gather.back);
    score(&gather.score);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        delta_time = sfClock_restart(clock).microseconds / 1000000.0;
        elapsed_time += delta_time;
        poll_event(window, &gather);
        if (gather.bird.death == 0) {
            updater(window, &gather);
            birdrect_speed(delta_time, &gather.bird);
            bird_passed(&gather);
            increase_score(&gather.score, window);
            if (gather.bird.while_jump == 0)
                fall(&gather.bird, delta_time);
            jump(&gather.bird);
            limit(&gather.enemy, &gather.bird);
        } else {
            death(&gather);
            my_printf("died\n");
        }
    }
    sfClock_destroy(clock);
    destroy_sprite(&gather, window);
}
