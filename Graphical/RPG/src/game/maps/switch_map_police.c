/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** switch_map_police
*/

#include "../../../include/func_name.h"

int place_outside_police(rpg_t *rpg)
{
    rpg->game->in_game->map->status = MAP_OUTSIDE_POLICE;
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE] =
    put_in_vector2f(-1941, -1723);
    destroy_enemies(rpg);
    begin_nmi_spawn(rpg);
    stop_car(rpg, TRUE);
    return (1);
}

int choose_outside_police_next(rpg_t *rpg)
{
    if (rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].x > 200 &&
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].y < -1500) {
        rpg->game->in_game->map->status = MAP_WARREN;
        rpg->game->in_game->map->pos_map[MAP_WARREN] =
        put_in_vector2f(-2200, -1650);
        destroy_enemies(rpg);
        begin_nmi_spawn(rpg);
            stop_car(rpg, TRUE);
        return (1);
    }
    if ((rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].x > -2000 &&
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].x < -1500) &&
    (rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].y > -1800 &&
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].y < -1500) &&
    rpg->game->in_game->map->status == MAP_OUTSIDE_POLICE) {
        rpg->game->in_game->map->status = MAP_INSIDE_POLICE;
        rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE] =
        put_in_vector2f(-1800, -1880);
        destroy_enemies(rpg);
        stop_car(rpg, FALSE);
        return (1);
    }
    return (0);
}

int choose_map_outside_police(rpg_t *rpg)
{
    if (choose_outside_police_next(rpg) == 1)
        return (1);
    if ((rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].x < -3500 &&
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].x > -3700) &&
    (rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].y > -2700 &&
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].y < 2300)) {
        rpg->game->in_game->map->status = MAP_OUTSIDE_CDC;
        rpg->game->in_game->map->pos_map[MAP_OUTSIDE_CDC] =
        put_in_vector2f(-100, -1400);
        destroy_enemies(rpg);
        begin_nmi_spawn(rpg);
        stop_car(rpg, FALSE);
        return (1);
    }
    if (rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].y < -2300 &&
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].y > -3000) {
        rpg->game->in_game->map->status = MAP_OUTSIDE_DISCO;
        rpg->game->in_game->map->pos_map[MAP_OUTSIDE_DISCO] =
        put_in_vector2f(-1200, -1600);
        destroy_enemies(rpg);
        begin_nmi_spawn(rpg);
        stop_car(rpg, FALSE);
        return (1);
    }
    return (0);
}

int choose_map_cdc_in(rpg_t *rpg)
{
    if (rpg->game->in_game->map->pos_map[MAP_INSIDE_CDC].y < -1500) {
        rpg->game->in_game->map->status = MAP_OUTSIDE_CDC;
        rpg->game->in_game->map->pos_map[MAP_OUTSIDE_CDC] =
        put_in_vector2f(-2060, -3300);
        destroy_enemies(rpg);
        begin_nmi_spawn(rpg);
        return (1);
    }
    if (rpg->game->in_game->map->pos_map[MAP_INSIDE_CDC].y > -1500 &&
    rpg->game->in_game->game_status == GM_ELEVATOR) {
        rpg->game->in_game->phone->notif_prev =
        rpg->game->in_game->phone->notif_index;
        rpg->menu->status = ON_CINEMATIC2;
        rpg->game->in_game->inventory->vaccine_status = FALSE;
        rpg->game->in_game->map->draw_car = FALSE;
        return (1);
    }
    return (0);
}

