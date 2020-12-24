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

void bird_sprite(sfRenderWindow *window, player_t *bird)
{
    bird->bird_tex = sfTexture_createFromFile("png/bird.png", NULL);
    bird->my_bird = sfSprite_create();
    sfVector2f scale = {0.35f, 0.35f};

    sfSprite_setPosition(bird->my_bird, bird->position);
    sfSprite_setTexture(bird->my_bird, bird->bird_tex, sfFalse);
    sfSprite_setTextureRect(bird->my_bird, bird->anim);
    sfSprite_setScale(bird->my_bird, scale);
    sfRenderWindow_drawSprite(window, bird->my_bird, NULL);
    if (bird->offset >= 3)
        bird->offset = 0;
    sfSprite_destroy(bird->my_bird);
    sfTexture_destroy(bird->bird_tex);
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
}

void birdrect_speed(float delta_time, player_t *bird)
{
    static float nbr = 0;

    // printf("%f\n", nbr);
    if (nbr >= 0.07f) {
        move_rect(bird);
        bird->offset++;
        nbr = 0;
    }
    nbr = delta_time + nbr;
}