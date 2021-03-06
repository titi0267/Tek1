/*
** EPITECH PROJECT, 2020
** display by Timothy CONIEL
** File description:
** display.c
*/
#include "../../include/my.h"

void create_window(window_t *windo)
{
    windo->video_mode.width = 1350;
    windo->video_mode.height = 947.25f;
    windo->video_mode.bitsPerPixel = 32;
    windo->window = sfRenderWindow_create(windo->video_mode,
                                        "Flappy Bird",sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(windo->window, 55);
}

void main_loop(map_t *buff, gather_t *gather)
{
    restart(gather, buff);
    poll_event(gather->windo.window, gather);
    update_time(&gather->time);
    if (gather->menu.stop_game == 0 || gather->score.win == 1)
        update_start(gather);
    if (gather->menu.game_starting == 1 && gather->menu.countdown <= 0) {
        if (gather->bird.death == 0 && gather->score.win == 0) {
            updater(gather);
            bird_action(gather);
        } else {
            death(gather);
            if (gather->score.win == 0)
                bird_fall_death(&gather->bird, &gather->windo, &gather->sound);
        }
    }
    best_score(&gather->score, gather->windo.window);
}

int keep_window_open(map_t *buff)
{
    gather_t gather;

    create_window(&gather.windo);
    if (call_init(&gather, buff) != 0)
        return (-1);
    while (sfRenderWindow_isOpen(gather.windo.window)) {
        sfRenderWindow_display(gather.windo.window);
        main_loop(buff, &gather);
    }
    destroy(&gather);
    sfRenderWindow_destroy(gather.windo.window);
    return (0);
}
