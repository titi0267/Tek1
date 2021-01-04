/*
** EPITECH PROJECT, 2020
** moving sprite by Timothy CONIEL
** File description:
** moving_sprite.c
*/
#include "../include/my.h"

void updater(sfRenderWindow *window, enemy_t *enemy, background_t *back, player_t *bird)
{
    background_update(window, back);
    bottom_update(window, back);
    pipe_update(window, enemy);
    collision(enemy, bird);
    bird_update(bird, window);
    bird_pass(enemy, bird);
}