/*
** EPITECH PROJECT, 2021
** update score by Timothy CONIEL
** File description:
** update_score.c
*/
#include "../../../include/my.h"

void your_score(score_t *score, sfRenderWindow *window)
{
    lib_t lib;
    sfVector2f pos_your = {375, 0};

    sfText_setPosition(score->your_score, pos_your);
    sfText_setString(score->your_score, "Your score: ");
    sfRenderWindow_drawText(window, score->your_score, NULL);
    pos_your.x = 825;
    sfText_setPosition(score->your_score, pos_your);
    score->current = my_revstr(my_int_str(score->actual, &lib), &lib);
    if (score->actual == 0)
        sfText_setString(score->your_score, "0");
    else
        sfText_setString(score->your_score, score->current);
    sfRenderWindow_drawText(window, score->your_score, NULL);
    free(score->current);
}

void best_score(score_t *score, sfRenderWindow *window)
{
    lib_t lib;

    score->pos_best.x = 5;
    sfText_setPosition(score->high_score, score->pos_best);
    sfText_setString(score->high_score, "Best score: ");
    sfRenderWindow_drawText(window, score->high_score, NULL);
    score->pos_best.x = 185;
    sfText_setPosition(score->high_score, score->pos_best);
    score->max_disp = my_revstr(my_int_str(score->max, &lib), &lib);
    if (score->max == 0)
        sfText_setString(score->high_score, "0");
    else
        sfText_setString(score->high_score, score->max_disp);
    sfRenderWindow_drawText(window, score->high_score, NULL);
    free(score->max_disp);
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
