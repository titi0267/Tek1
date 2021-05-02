/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** tuto
*/

#include "../../include/func_name.h"

// point_distcance(put_in_vector2f(690, 584),
//     put_in_vector2f(rpg->game->in_game->objects->car->car_pos.x,
//     rpg->game->in_game->objects->car->car_pos.y + 10)) <= 5

int car_dist(rpg_t *rpg)
{
    sfVector2f check = vect_diff(put_in_vector2f(rpg->game->in_game->objects->car->car_pos.x, rpg->game->in_game->objects->car->car_pos.y + 10),
    put_in_vector2f(690, 584));

    printf("%f ||%f\n", check.x, check.y);
    if ((check.x > 12 || check.x < 0) || (check.y < -5 && check.y > 5))
        return (FALSE);
    return (TRUE);
}

void enterred_in_car(rpg_t *rpg)
{
    static float nbr = 0;
    sfVector2f diff;

    nbr += rpg->basic->cnf->clk->time_loop;
    if (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[CAR]->text[0] &&
    nbr >= 0.2 && car_dist(rpg)) {
        rpg->game->in_game->objects->speed_status =
        (rpg->game->in_game->objects->speed_status != CAR_SPEED) ? CAR_SPEED :
        WALK_SPEED;
        nbr = 0;
        diff = vect_diff(put_in_vector2f(rpg->game->in_game->objects->car->car_pos.x,
        rpg->game->in_game->objects->car->car_pos.y + 10), put_in_vector2f(690, 584));
        printf("%f || %f\n", diff.x, diff.y);
        rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status] = vect_add(rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status], diff);
        sfSprite_setPosition(
        rpg->game->in_game->map->maps[rpg->game->in_game->map->status],
        rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status]);
    }
}