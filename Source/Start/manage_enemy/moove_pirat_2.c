/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** moove_pirat_2
*/

#include "../../../include/defender.h"

int attack(core_t *core, pirat_data_t *data, sfVector2f pos)
{
    core->game->lifepoint -= 5;
    data->dead = 1;
    if (core->game->lifepoint <= 0)
        sfRenderWindow_close(core->wnd->window);
    return (0);
}

int move_bis_bis(core_t *core, pirat_data_t *data, sfVector2f pos)
{
    if (pos.x == 83 && pos.y > 260) {
        data->pos.y -= 0.5;
        return (0);
    } else if (pos.x == 83 && pos.y >= 260) {
        data->pos.x = 82;
        data->pos.y = 259;
        return (0);
    }
    if (pos.x == 82 && pos.y > 100) {
        data->pos.y -= data->speed;
        return (0);
    } else if (pos.x == 82 && pos.y >= 100) {
        data->pos.x = 82;
        data->pos.y = 99;
        return (0);
    }
    if (pos.x == 82 && pos.y == 99) {
        attack(core, data, pos);
        return (0);
    }
}

int move_bis(core_t *core, pirat_data_t *data, sfVector2f pos)
{
    if (pos.x > 85 && pos.y == 809) {
        data->pos.x -= data->speed;
        return (0);
    } else if (pos.x >= 85 && pos.y == 809) {
        data->pos.x = 84;
        data->pos.y = 808;
        return (0);
    }
    if (pos.x == 84 && pos.y > 430) {
        data->pos.y -= data->speed;
        return (0);
    } else if (pos.x == 84 && pos.y >= 430) {
        data->pos.x = 83;
        data->pos.y = 429;
        return (0);
    } else
        move_bis_bis(core, data, pos);
}

int move_bis_bis_bis(core_t *core, pirat_data_t *data, sfVector2f pos)
{
    if (pos.x > 543 && pos.y == 174) {
        data->pos.x -= data->speed;
        return (0);
    } else if (pos.x >= 543 && pos.y == 174) {
        data->pos.x = 542;
        data->pos.y = 173;
        return (0);
    }
    if (pos.x == 542 && pos.y < 810) {
        data->pos.y += data->speed;
        return (0);
    } else if (pos.x == 542 && pos.y <= 810) {
        data->pos.x = 541;
        data->pos.y = 809;
        return (0);
    } else
        move_bis(core, data, pos);
    return (0);
}

int move_road2(core_t *core, pirat_data_t *data)
{
    sfVector2f pos = sfSprite_getPosition(data->pirat_walk);

    if (pos.x > 850 & pos.y == 40) {
        data->pos.x -= data->speed;
        return (0);
    } else if (pos.x >= 850 & pos.y == 40) {
        data->pos.x = 849;
        data->pos.y = 40;
        return (0);
    }
    if (pos.x == 849 && pos.y < 175) {
        data->pos.y += data->speed;
        return (0);
    } else if (pos.x == 849 && pos.y <= 175) {
        data->pos.x = 848;
        data->pos.y = 174;
        return (0);
    } else
        move_bis_bis_bis(core, data, pos);
}