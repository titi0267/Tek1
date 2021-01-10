/*
** EPITECH PROJECT, 2021
** init score by Timothy CONIEL
** File description:
** init_score.c
*/
#include "../../include/my.h"

void reset_score(score_t *score)
{
    score->amount = 0;
    score->increase_score = 0;
}

void init_score_next(score_t *score)
{
    sfVector2f position = {583, 83};
    score->position_increase.x = 630;
    score->position_increase.y = 83;
    score->pos_best.x = 0;
    score->pos_best.y = 0;
    sfVector2f position_score = {500, 0};
    sfText_setPosition(score->text, position);
    sfText_setPosition(score->high_score, score->pos_best);
    sfText_setPosition(score->text_increase, score->position_increase);
    sfText_setPosition(score->text_score, position_score);
    reset_score(score);
}
