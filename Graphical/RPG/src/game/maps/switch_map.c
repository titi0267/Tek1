/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** switch_map
*/

#include "../../../include/func_name.h"

int choose_map_warren(rpg_t *rpg)
{
    if (rpg->game->in_game->map->pos_map[MAP_WARREN].y > -2000) {
        rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE] =
        put_in_vector2f(200, -1870);
        rpg->game->in_game->map->status = MAP_OUTSIDE_POLICE;
        destroy_enemies(rpg);
        begin_nmi_spawn(rpg);
        stop_car(rpg, TRUE);
        return (1);
    }
    if (rpg->game->in_game->map->pos_map[MAP_WARREN].y < -2500) {
        rpg->game->in_game->map->status = MAP_OUTSIDE_DISCO;
        rpg->game->in_game->map->pos_map[MAP_OUTSIDE_DISCO] =
        put_in_vector2f(-200, -2380);
        destroy_enemies(rpg);
        begin_nmi_spawn(rpg);
        stop_car(rpg, FALSE);
        return (1);
    }
    return (0);
}

int choose_map_outside_cdc(rpg_t *rpg)
{
    if ((rpg->game->in_game->map->pos_map[MAP_OUTSIDE_CDC].y > -1500 &&
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_CDC].y < -1200)) {
        rpg->game->in_game->map->status = MAP_OUTSIDE_POLICE;
        rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE] =
        put_in_vector2f(-3500, -2470);
        destroy_enemies(rpg);
        begin_nmi_spawn(rpg);
        stop_car(rpg, TRUE);
        return (1);
    }
    if (rpg->game->in_game->map->pos_map[MAP_OUTSIDE_CDC].y < -2000 &&
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_CDC].x > -1500) {
        rpg->game->in_game->map->status = MAP_OUTSIDE_DISCO;
        rpg->game->in_game->map->pos_map[MAP_OUTSIDE_DISCO] =
        put_in_vector2f(-2400, -2350);
        destroy_enemies(rpg);
        begin_nmi_spawn(rpg);
        stop_car(rpg, FALSE);
        return (1);
    }
    if (rpg->game->in_game->map->pos_map[MAP_OUTSIDE_CDC].y < -2000 &&
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_CDC].x < -1500) {
        rpg->game->in_game->map->status = MAP_INSIDE_CDC;
        rpg->game->in_game->map->pos_map[MAP_INSIDE_CDC] =
        put_in_vector2f(-1348, -2012);
        destroy_enemies(rpg);
        return (1);
    }
    return (0);
}

int choose_map_outside_disco(rpg_t *rpg)
{
    if (rpg->game->in_game->map->pos_map[MAP_OUTSIDE_DISCO].y > -1750) {
        rpg->game->in_game->map->status = MAP_OUTSIDE_POLICE;
        rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE] =
        put_in_vector2f(-1880, -2650);
        destroy_enemies(rpg);
        begin_nmi_spawn(rpg);
        stop_car(rpg, TRUE);
        return (1);
    }
    if (rpg->game->in_game->map->pos_map[MAP_OUTSIDE_DISCO].y < -1800 &&
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_DISCO].x > -1500) {
        rpg->game->in_game->map->status = MAP_WARREN;
        rpg->game->in_game->map->pos_map[MAP_WARREN] =
        put_in_vector2f(-2500, -3345);
        destroy_enemies(rpg);
        begin_nmi_spawn(rpg);
        stop_car(rpg, TRUE);
        return (1);
    }
    if (rpg->game->in_game->map->pos_map[MAP_OUTSIDE_DISCO].y < -1900 &&
    rpg->game->in_game->map->pos_map[MAP_OUTSIDE_DISCO].x < -2000) {
        rpg->game->in_game->map->status = MAP_OUTSIDE_CDC;
        rpg->game->in_game->map->pos_map[MAP_OUTSIDE_CDC] =
        put_in_vector2f(-500, -2800);
        destroy_enemies(rpg);
        begin_nmi_spawn(rpg);
        return (1);
    }
    return (0);
}

void warp_map_next(rpg_t *rpg)
{
    if (rpg->game->in_game->map->status == MAP_OUTSIDE_POLICE)
        if (choose_map_outside_police(rpg) == 1) return;
    if (rpg->game->in_game->map->status == MAP_WARREN)
        if (choose_map_warren(rpg) == 1) return;
    if (rpg->game->in_game->map->status == MAP_OUTSIDE_CDC)
        if (choose_map_outside_cdc(rpg) == 1) return;
    if (rpg->game->in_game->map->status == MAP_OUTSIDE_DISCO)
        if (choose_map_outside_disco(rpg) == 1) return;
}

void change_map(rpg_t *rpg)
{
    if (rpg->game->in_game->map->status == MAP_TUTO) {
        rpg->menu->status = ON_MENU;
        rpg->game->in_game->map->status = MAP_INSIDE_POLICE;
    }
    if (rpg->game->in_game->map->status == MAP_INSIDE_POLICE)
        if (place_outside_police(rpg) == 1) return;
    if (rpg->game->in_game->map->status == MAP_INSIDE_CDC)
        if (choose_map_cdc_in(rpg) == 1) return;
    warp_map_next(rpg);
}