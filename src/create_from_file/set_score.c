/*
** EPITECH PROJECT, 2021
** set score by Timothy CONIEL
** File description:
** set_score.c
*/
#include "../../include/my.h"

void init_score(score_t *score)
{
    score->text = sfText_create();
    score->high_score = sfText_create();
    score->your_score = sfText_create();
    score->text_score = sfText_create();
    score->text_increase = sfText_create();
    score->font = sfFont_createFromFile("ressource/score.ttf");
    sfText_setFont(score->text, score->font);
    sfText_setFont(score->high_score, score->font);
    sfText_setFont(score->your_score, score->font);
    sfText_setFont(score->text_increase, score->font);
    sfText_setFont(score->text_score, score->font);
    sfText_setCharacterSize(score->text, 75);
    sfText_setCharacterSize(score->your_score, 75);
    sfText_setCharacterSize(score->high_score, 30);
    sfText_setCharacterSize(score->text_increase, 75);
    sfText_setCharacterSize(score->text_score, 75);
    sfText_setColor(score->text, sfWhite);
    sfText_setColor(score->your_score, sfBlack);
    sfText_setColor(score->high_score, sfBlack);
    sfText_setColor(score->text_increase, sfWhite);
    sfText_setColor(score->text_score, sfWhite);
}