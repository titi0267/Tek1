/*
** EPITECH PROJECT, 2021
** update score by Timothy CONIEL
** File description:
** update_score.c
*/
#include "../../../include/my.h"

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

void bird_after_pipe(gather_t *gather)
{
    while (gather->bird.aft_pip <= 16) {
        if (gather->bird.collision[gather->bird.aft_pip].x < 170 &&
            gather->bird.collision[gather->bird.aft_pip].x >= 166)
            break;
        gather->bird.aft_pip++;
    }
    if (gather->bird.aft_pip != 17) {
        sfSound_play(gather->sound.coin);
        gather->score.amount++;
    }
    gather->bird.aft_pip = 1;
}
