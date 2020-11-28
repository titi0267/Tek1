/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-timothe.coniel
** File description:
** duck
*/
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my_struct.h"
#include "include/my.h"

void move_rect(duck_t *pos)
{
    if (pos->offset < 3)
        pos->rect.left = pos->offset * pos->rect.width;
}

void move_straight(sfRenderWindow *window, duck_t *pos)
{
    pos->duck_straight = sfTexture_createFromFile("all_sprites/mvts/duckduck.png", NULL);
    pos->my_duck_straight = sfSprite_create();
    pos->scale = (sfVector2f){1.0f, 1.0f};

    sfSprite_setPosition(pos->my_duck_straight, pos->position);
    sfSprite_setTexture(pos->my_duck_straight, pos->duck_straight, sfFalse);
    sfSprite_setTextureRect(pos->my_duck_straight, pos->rect);
    sfSprite_setScale(pos->my_duck_straight, pos->scale);
    sfRenderWindow_drawSprite(window, pos->my_duck_straight, NULL);
    edge_window(window, pos);
    sfSprite_destroy(pos->my_duck_straight);
    sfTexture_destroy(pos->duck_straight);
}

void birdrect_speed(duck_t *pos, float delta_time)
{
    static float nbr = 0;
    float rest = 0;

    if (nbr >= 0.1f) {
        nbr -= 0.1f;
        rest = rest + nbr;
        nbr -= rest;
        //printf("Rest : %f\n", rest);
        move_rect(pos);
        pos->offset++;
    }
    nbr = delta_time + nbr;
    //printf("Time Duck : %i\n", nbr);
}

void init_duck(duck_t *pos)
{
    pos->position.x = -120;
    pos->position.y = 0;
    pos->rect.top = 0;
    pos->rect.left = 0;
    pos->rect.height = 110;
    pos->rect.width = 110;
    pos->offset = 0;
}