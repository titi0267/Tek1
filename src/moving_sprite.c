/*
** EPITECH PROJECT, 2020
** moving sprite by Timothy CONIEL
** File description:
** moving_sprite.c
*/
#include "../include/my.h"

void updater(sfRenderWindow *window, gather_t *gather)
{
    background_update(window, &gather->back);
    bottom_update(window, &gather->back);
    pipe_update(window, &gather->enemy);
    collision(&gather->enemy, &gather->bird);
    bird_update(&gather->bird, window);
    bird_pass(&gather->enemy, &gather->bird);
}