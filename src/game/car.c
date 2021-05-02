/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** tuto
*/

#include "../../include/func_name.h"

static void good_enter(rpg_t *rpg)
{
    sfVector2f diff;

    diff = vect_diff(put_in_vector2f(rpg->game->in_game->objects->car->
    car_pos.x, rpg->game->in_game->objects->car->car_pos.y + 10),
    put_in_vector2f(690, 560));
    printf("%f ||%f\n", diff.x, diff.y);
    diff.x += 20;
    diff.y = 0;
    rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status] =
    vect_add(rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status],
    diff);
}

int car_dist(rpg_t *rpg)
{
    sfVector2f check = vect_diff(put_in_vector2f(
    rpg->game->in_game->objects->car->car_pos.x + 5,
    rpg->game->in_game->objects->car->car_pos.y + 10),
    put_in_vector2f(690, 560));

    printf("%f ||| %f\n", check.x, check.y);
    if ((check.x <= 30 && check.x >= 0) && (check.y >= -20 && check.y <= 20))
        return (TRUE);
    return (FALSE);
}

void enter_car(rpg_t *rpg)
{
    static float nbr = 0;

    nbr += rpg->basic->cnf->clk->time_loop;
    if (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[CAR]->text[0] &&
    nbr >= 0.2 && car_dist(rpg)) {
        rpg->game->in_game->objects->speed_status =
        (rpg->game->in_game->objects->speed_status != CAR_SPEED) ? CAR_SPEED :
        WALK_SPEED;
        nbr = 0;
        good_enter(rpg);
        sfSprite_setPosition(
        rpg->game->in_game->map->maps[rpg->game->in_game->map->status],
        rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status]);
    }
}