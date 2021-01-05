/*
** EPITECH PROJECT, 2020
** Bird by Timothy CONIEL
** File description:
** bird.c
*/
#include "../include/my.h"

void move_rect(player_t *bird)
{
    if (bird->offset < 3)
        bird->anim.left = bird->offset * bird->anim.width;
}

void bird_init(player_t *bird)
{
    bird->position.x = 250;
    bird->position.y = 400;
    bird->anim.left = 0;
    bird->anim.top = 0;
    bird->anim.width = 173.666f;
    bird->anim.height = 122;
    bird->offset = 0;
    bird->while_jump = 0;
    bird->second_jump = 0;
    bird->rotation = 0;
    bird->stop_jump = 0;
    bird->fall_fast = 1;
    bird->death = 0;
    bird->fit_space = 0;
    bird->high = 0;
}

void bird_sprite(player_t *bird)
{
    bird->bird_tex = sfTexture_createFromFile("png/bird.png", NULL);
    bird->my_bird = sfSprite_create();
    sfVector2f scale = {0.35f, 0.35f};

    sfSprite_setTexture(bird->my_bird, bird->bird_tex, sfFalse);
    sfSprite_setScale(bird->my_bird, scale);
    bird_init(bird);
}

void bird_update(player_t *bird, sfRenderWindow *window)
{
    if (bird->offset >= 3)
        bird->offset = 0;
    sfSprite_setPosition(bird->my_bird, bird->position);
    sfSprite_setTextureRect(bird->my_bird, bird->anim);
    sfRenderWindow_drawSprite(window, bird->my_bird, NULL);
}

void birdrect_speed(float delta_time, player_t *bird)
{
    static float nbr = 0;

    if (nbr >= 0.09f) {
        move_rect(bird);
        bird->offset++;
        nbr = 0;
    }
    nbr = delta_time + nbr;
}