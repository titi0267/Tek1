/*
** EPITECH PROJECT, 2021
** win by Timothy CONIEL
** File description:
** win.c
*/
#include "../../../include/my.h"

void congrats(gather_t *gather)
{
    sfRenderWindow_drawSprite(gather->windo.window, gather->back.winner, NULL);
    gather->bird.rotation = 0;
    sfSprite_setRotation(gather->bird.my_bird, gather->bird.rotation);
}