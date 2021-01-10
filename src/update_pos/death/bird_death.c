/*
** EPITECH PROJECT, 2021
** birds death by Timothy CONIEL
** File description:
** bird_death.c
*/
#include "../../../include/my.h"

void bird_fall_speed(player_t *bird)
{
    if (bird->position.y <= 200 && bird->position.y > 0) {
        bird->fall_dead = 13;
        bird->angle_down = 2;
        bird->stop = 1;
    }
    if (bird->position.y < 400 && bird->position.y > 200) {
        bird->fall_dead = 8;
        bird->angle_down = 3;
        bird->stop = 1;
    }
    if (bird->position.y < 550 && bird->position.y >= 400) {
        bird->fall_dead = 6;
        bird->angle_down = 4;
        bird->stop = 1;
    }
    if (bird->position.y >= 550 && bird->position.y <= 720) {
        bird->fall_dead = 3;
        bird->angle_down = 5;
        bird->stop = 1;
    }
}

void bird_fall_death(player_t *bird, window_t *windo)
{
    float angle_bottom = bird->rotation;

    if (bird->position.y < 0)
        bird->position.y = 0;
    if (bird->stop == 0)
        bird_fall_speed(bird);
    if (bird->position.y < 720) {
        bird->position.y += bird->fall_dead;
        if (bird->angle <= 85)
            bird->angle += bird->angle_down;
    }
    if (bird->position.y >= 720 && bird->stop == 0) {
        sfSprite_setRotation(bird->my_bird, angle_bottom);
        bird->stop = 1;
    } else
        sfSprite_setRotation(bird->my_bird, bird->angle);
    sfSprite_setPosition(bird->my_bird, bird->position);
    sfRenderWindow_drawSprite(windo->window, bird->my_bird, NULL);
}
