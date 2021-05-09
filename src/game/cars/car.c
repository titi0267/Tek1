/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** tuto
*/

#include "../../../include/func_name.h"

static void good_enter(rpg_t *rpg, sfFloatRect car, sfFloatRect player)
{
    if (rpg->game->in_game->map->status == MAP_TUTO) {
        rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status].x
        += (player.left - car.left);
        rpg->game->in_game->objects->car->car_pos_tuto.x +=
        (player.left - car.left);
        rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status].y +=
        (player.top - car.top);
        rpg->game->in_game->objects->car->car_pos_tuto.y +=
        (player.top - car.top);
    } else {
        rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status].x
        += (player.left - car.left);
        rpg->game->in_game->objects->car->car_pos.x += (player.left - car.left);
        rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status].y +=
        (player.top - car.top);
        rpg->game->in_game->objects->car->car_pos.y += (player.top - car.top);
    }
}

int car_dist(sfFloatRect car, sfFloatRect player)
{
    if (player.left >= car.left - 60 && player.left + player.width <=
    car.left + car.width + 60 &&
    player.top >= car.top - 108  && player.top + player.height <=
    car.top + car.height + 108)
        return (TRUE);
    return (FALSE);
}

void enter_car(rpg_t *rpg)
{
    static float nbr = 0;
    sfFloatRect car = sfSprite_getGlobalBounds
    (rpg->game->in_game->objects->car->car);
    sfFloatRect player = sfSprite_getGlobalBounds(rpg->game->in_game->objects
    ->players[rpg->menu->main_menu->new_game->character_chosen]);

    nbr += rpg->basic->cnf->clk->time_loop;
    if ((rpg->basic->evt->event.type == sfEvtTextEntered) &&
    (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[CAR]->text[0] &&
    nbr >= 0.2 && car_dist(car, player) == TRUE)) {
        rpg->game->in_game->objects->speed_status =
        (rpg->game->in_game->objects->speed_status != CAR_SPEED) ? CAR_SPEED :
        WALK_SPEED;
        nbr = 0;
        good_enter(rpg, car, player);
        sfSprite_setPosition(
        rpg->game->in_game->map->maps[rpg->game->in_game->map->status],
        rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status]);
        if (rpg->game->in_game->map->status == MAP_TUTO)
            sfSprite_setPosition(rpg->game->in_game->objects->car->car,
            rpg->game->in_game->objects->car->car_pos_tuto);
        else
            sfSprite_setPosition(rpg->game->in_game->objects->car->car,
            rpg->game->in_game->objects->car->car_pos);
    }
}

void stop_car(objects_t *obj, float x, float y)
{
    obj->speed_status = WALK_SPEED;
    obj->car->car_pos = put_in_vector2f(x, y);
    obj->car->draw = FALSE;
}