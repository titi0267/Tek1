/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** moove_pirat
*/

#include "../../../include/defender.h"
#include <stdio.h>

int manage_move(core_t *core, pirat_data_t *data)
{
    sfVector2f pos = sfSprite_getPosition(data->pirat_walk);

    if (pos.y == 810 && pos.x > 1075) {
        data->pos.x -= data->speed;
        return (0);
    }
    else if (pos.x <= 1075 && pos.x >= 1072 && pos.y == 810) {
        data->pos.x = 1075;
        data->pos.y = 809;
        return (0);
    }
    if (pos.y > 390 && pos.x == 1075) {
        data->pos.y -= data->speed;
        return (0);
    }
    else if (pos.x == 1075 && pos.y <= 390 && pos.y >= 386) {
        data->pos.y = 389;
        data->pos.x = 1074;
        return (0);
    }
    if (pos.x > 530 && pos.y == 389) {
        data->pos.x -= data->speed;
        return (0);
    }
    else if (pos.x <= 530 && pos.x >= 526 && pos.y == 389) {
        data->pos.x = 531;
        data->pos.y = 391;
        return (0);
    }
    if (pos.x == 531 && pos.y < 800) {
        data->pos.y += data->speed;
        return (0);
    } else if (pos.y >= 800 && pos.x == 531) {
        data->pos.x = 529;
        data->pos.y = 801;
        return (0);
    }
    if (pos.y == 801 && pos.x > 170) {
        data->pos.x -= data->speed;
        return (0);
    } else if (pos.y == 801 && pos.x <= 170) {
        data->pos.x = 169;
        data->pos.y = 799;
        return (0);
    }
    if (pos.x == 169 && pos.y > 430) {
        data->pos.y -= data->speed;
        return (0);
    } else if (pos.x == 169 && pos.y >= 430) {
        data->pos.x = 168;
        data->pos.y = 429;
        return (0);
    }
    if (pos.x == 168 && pos.y > 259) {
        data->pos.y -= 0.5;
        return (0);
    } else if (pos.x == 168 && pos.y >= 259) {
        data->pos.x = 167;
        data->pos.y = 258;
        return (0);
    }
    if (pos.x == 167 && pos.y > 100) {
        data->pos.y -= data->speed;
        return (0);
    } else if (pos.x == 167 && pos.y >= 100) {
        data->pos.x = 166;
        data->pos.y = 99;
        return (0);
    }
    if (pos.x == 166 && pos.y == 99) {
        attack(core, data, pos);
        return (0);
    }
}

int moove_pirat(core_t *core, pirat_data_t *data)
{
    sfVector2f scale = {0.37, 0.37};

    if (data->dead == 0 && core->menu->pause_on == FALSE) {
        if (data->road == 1)
            manage_move(core, data);
        else
            move_road2(core, data);
        moove_rect(core);
        range_def(core->game, core->enemy, core->time);
        sfSprite_setPosition(data->pirat_walk, data->pos);
        sfSprite_setTextureRect(data->pirat_walk, core->enemy->pirat->rectangle);
        sfSprite_setScale(data->pirat_walk, scale);
        sfRenderWindow_drawSprite(core->wnd->window, data->pirat_walk, NULL);
        check_life(core);
    }
    return (0);
}