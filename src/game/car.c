/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** tuto
*/

#include "../../include/func_name.h"

void enterred_in_car(rpg_t *rpg)
{
    static float nbr = 0;

    nbr += rpg->basic->cnf->clk->time_loop;
    if (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[CAR]->text[0] &&
    nbr >= 0.2 && point_distcance(put_in_vector2f(660, 540),
    put_in_vector2f(rpg->game->in_game->objects->car->car_pos.x + 50,
    rpg->game->in_game->objects->car->car_pos.y + 50)) <= 60) {
        rpg->game->in_game->objects->speed_status =
        (rpg->game->in_game->objects->speed_status != CAR_SPEED) ? CAR_SPEED :
        WALK_SPEED;
        nbr = 0;
        rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status] =
        put_in_vector2f(-1700, -847);
        sfSprite_setPosition(
        rpg->game->in_game->map->maps[rpg->game->in_game->map->status],
        rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status]);
    }
}