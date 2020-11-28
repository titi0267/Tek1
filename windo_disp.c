/*
** EPITECH PROJECT, 2020
** csfml
** File description:
** windo_disp
*/
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my_struct.h"
#include "include/my.h"

void sprite(sfRenderWindow *window)
{
    sfTexture *background = sfTexture_createFromFile("all_sprites/map/background.png", NULL);
    sfSprite *my_background = sfSprite_create();
    sfVector2f scale = {2, 2};

    sfSprite_setTexture(my_background, background, sfFalse);
    sfSprite_setScale(my_background, scale);
    sfRenderWindow_drawSprite(window, my_background, NULL);
    sfSprite_destroy(my_background);
    sfTexture_destroy(background);
}

void keep_window_open(void)
{
    sfRenderWindow *window;
    duck_t pos;
    sfVideoMode video_mode = {902, 744, 32};
    sfClock *clock = sfClock_create();
    float elapsed_time = 0;
    float delta_time = 0;

    init_duck(&pos);
    window = sfRenderWindow_create(video_mode, "MyWindow", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        poll_event(window, &pos);
        sprite(window);
        move_straight(window, &pos);
        if (pos.offset >= 3)
            pos.offset = 0;
        delta_time = sfClock_restart(clock).microseconds / 1000000.0;
        elapsed_time += delta_time;
        birdrect_speed(&pos, delta_time);
    }
    sfRenderWindow_destroy(window);
}

int main(void)
{
    keep_window_open();
}