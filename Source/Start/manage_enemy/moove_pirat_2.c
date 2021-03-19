/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** moove_pirat_2
*/

#include "../../../include/defender.h"

int attack(core_t *core, pirat_data_t *data, sfVector2f pos)
{
    core->game->lifepoint -= 0.01;
    if (core->game->lifepoint <= 0)
        sfRenderWindow_close(core->wnd->window);
    return (0);
}

int move_bis(core_t *core, pirat_data_t *data, sfVector2f pos)
{
    if (pos.x == 160 && pos.y > 250)
        data->pos.y--;
    else if (pos.x == 160 && pos.y > 100)
        data->pos.y--;
    if (pos.x == 160 && pos.y == 100)
        attack(core, data, pos);
    return (0);
}

int move_road2(core_t *core, pirat_data_t *data)
{
    sfVector2f pos = sfSprite_getPosition(data->pirat_walk);

    if (pos.y == 40 && pos.x > 850)
        data->pos.x--;
    else if (pos.x == 850 && pos.y < 190)
        data->pos.y++;
    if (pos.y == 190 && pos.x > 540)
        data->pos.x--;
    else if (pos.x == 540 && pos.y < 815)
        data->pos.y++;
    if (pos.y == 815 && pos.x > 160)
        data->pos.x--;
    else if(pos.x == 160 && pos.y > 420)
        data->pos.y--;
    else
        move_bis(core, data, pos);
    return (0);
}