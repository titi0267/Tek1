/*
** EPITECH PROJECT, 2021
** score by Timothy CONIEL
** File description:
** score.c
*/
#include "../include/my.h"

void init_score(score_t *score)
{
    score->text = sfText_create();
    score->text_score = sfText_create();
    score->text_increase = sfText_create();
    score->font = sfFont_createFromFile("png/score.ttf");
    sfText_setFont(score->text, score->font);
    sfText_setFont(score->text_increase, score->font);
    sfText_setFont(score->text_score, score->font);
    sfText_setCharacterSize(score->text, 75);
    sfText_setCharacterSize(score->text_increase, 75);
    sfText_setCharacterSize(score->text_score, 75);
    sfText_setColor(score->text, sfWhite);
    sfText_setColor(score->text_increase, sfWhite);
    sfText_setColor(score->text_score, sfWhite);
}

void init_score_next(score_t *score)
{
    sfVector2f position = {583, 83};
    score->position_increase.x = 630;
    score->position_increase.y = 83;
    sfVector2f position_score = {500, 0};
    sfText_setPosition(score->text, position);
    sfText_setPosition(score->text_increase, score->position_increase);
    sfText_setPosition(score->text_score, position_score);
    score->amount = 0;
    score->increase_score = 0;
}

void increase_score(score_t *score, sfRenderWindow *window)
{
    lib_t lib;

    score->score_disp =  my_revstr(my_int_str(score->amount, &lib), &lib);
    sfText_setString(score->text_score, "SCORE:\n");
    sfText_setString(score->text_increase, score->score_disp);
    if (score->amount == 0)
        sfText_setString(score->text_increase, "0");
    if (score->amount < 10) {
        sfText_setString(score->text, "0");
        sfRenderWindow_drawText(window, score->text, NULL);
    }
    if (score->amount >= 10)
        score->position_increase.x = 583;
    sfText_setPosition(score->text_increase, score->position_increase);
    sfRenderWindow_drawText(window, score->text_score, NULL);
    sfRenderWindow_drawText(window, score->text_increase, NULL);
    free(score->score_disp);
}