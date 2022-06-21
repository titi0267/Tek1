/*
** EPITECH PROJECT, 2021
** set bird by Timothy CONIEL
** File description:
** set_bird.c
*/
#include "../../include/my.h"

void bird_sprite(player_t *bird)
{
    bird->bird_tex = sfTexture_createFromFile("ressource/img/bird.png", NULL);
    bird->my_bird = sfSprite_create();
    sfVector2f scale = {0.35f, 0.35f};

    sfSprite_setTexture(bird->my_bird, bird->bird_tex, sfFalse);
    sfSprite_setScale(bird->my_bird, scale);
    bird_init(bird);
}
