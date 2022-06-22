/*
** EPITECH PROJECT, 2021
** bird animation by Timothy CONIEL
** File description:
** bird_animation.c
*/
#include "../../include/my.h"

void move_rect(player_t *bird)
{
    if (bird->offset < 3)
        bird->anim.left = bird->offset * bird->anim.width;
}

void bird_update(player_t *bird, sfRenderWindow *window)
{
    if (bird->offset >= 3)
        bird->offset = 0;
    sfSprite_setPosition(bird->my_bird, bird->position);
    sfSprite_setTextureRect(bird->my_bird, bird->anim);
    sfSprite_setRotation(bird->my_bird, bird->rotation);
    sfRenderWindow_drawSprite(window, bird->my_bird, NULL);
}

void bird_anim_speed(time_t *time, player_t *bird)
{
    static float nbr = 0;

    if (nbr >= 0.09f) {
        move_rect(bird);
        bird->offset++;
        nbr = 0;
    }
    nbr = time->delta_time + nbr;
}
