/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** moove_pirat
*/

#include "../../../include/defender.h"

void manage_move_bis_bis(core_t *core, pirat_data_t *data, sfVector2f pos)
{
    if (pos.x == 90 && pos.y > 250)
        data->pos.y -= 0.5;
    else if (pos.x == 90 && pos.y > 100)
        data->pos.y--;
    if (pos.x == 90 && pos.x == 100)
        attack(core, data, pos);
}

void manage_move_bis(core_t *core, pirat_data_t *data, sfVector2f pos)
{
    if (pos.y == 365 && pos.x > 550)
        data->pos.x--;
    else if (pos.x == 550 && pos.y < 815)
        data->pos.y++;
    if (pos.y == 815 && pos.x > 90)
        data->pos.x--;
    else if (pos.x == 90 && pos.y > 420)
        data->pos.y--;
    else
        manage_move_bis_bis(core, data, pos);
}

void manage_move(core_t *core, pirat_data_t *data)
{
    sfVector2f pos = sfSprite_getPosition(data->pirat_walk);

    if (pos.x > 1075 && pos.y == 810) {
        data->pos.x -= 1;
    } else if (pos.x == 1075 && pos.y > 365)
        data->pos.y--;
    else
        manage_move_bis(core, data, pos);
}

int moove_pirat(core_t *core)
{
    pirat_data_t *data = *(core->enemy->data);
    static float nbr = 0;

    for (int i = 0; i < core->wave->pirate_one; i++) {
        if (data->road == 1)
            manage_move(core, data);
        else
            move_road2(core, data);
        nbr += core->time->delta_time;
        data = data->next;
    }
    return (0);
}