/*
** EPITECH PROJECT, 2021
** main update pos by Timothy CONIEL
** File description:
** main_update_pos.c
*/
#include "../../include/my.h"

void updater(gather_t *gather)
{
    pipe_update(gather->windo.window, &gather->enemy);
    move_pipe_array(&gather->bird);
    bird_btw_pipe(&gather->bird);
    increase_score(&gather->score, gather->windo.window);
    bird_after_pipe(gather);
    if (gather->score.amount >= 16) {
        gather->score.win = 1;
    }
}
