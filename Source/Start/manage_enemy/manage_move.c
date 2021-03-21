/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** manage_move
*/

#include "../../../include/defender.h"

int moove_pirat(core_t *core, pirat_data_t *data)
{
    sfVector2f scale = {0.37, 0.37};

    if (data->dead == 0) {
        if (core->menu->pause_on == FALSE) {
            if (core->game->init_def == TRUE)
                range_def(core->game, core->enemy, core->time);
            if (data->road == 1)
                manage_move(core, data);
            else
                move_road2(core, data);
            moove_rect(core);
        }
        sfSprite_setPosition(data->pirat_walk, data->pos);
        sfSprite_setTextureRect(data->pirat_walk,
            core->enemy->pirat->rectangle);
        sfSprite_setScale(data->pirat_walk, scale);
        sfRenderWindow_drawSprite(core->wnd->window, data->pirat_walk, NULL);
        check_life(core);
    }
    return (0);
}