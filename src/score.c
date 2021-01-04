/*
** EPITECH PROJECT, 2021
** score by Timothy CONIEL
** File description:
** score.c
*/
#include "../include/my.h"

void score(sfText *text, sfFont *font, sfRenderWindow *window)
{
    sfText_setString(text, "SCORE :");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 75);
    sfText_setColor(text, sfBlack);
    sfVector2f position = {500, 0};
    sfText_setPosition(text, position);
}