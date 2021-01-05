/*
** EPITECH PROJECT, 2021
** score by Timothy CONIEL
** File description:
** score.c
*/
#include "../include/my.h"

void score(score_t *score, sfRenderWindow *window)
{
    score->text = sfText_create();
    score->font = sfFont_createFromFile("png/Amatic-Bold.ttf");
    sfText_setString(score->text, "SCORE :");
    sfText_setFont(score->text, score->font);
    sfText_setCharacterSize(score->text, 75);
    sfText_setColor(score->text, sfBlack);
    sfVector2f position = {500, 0};
    sfText_setPosition(score->text, position);
}