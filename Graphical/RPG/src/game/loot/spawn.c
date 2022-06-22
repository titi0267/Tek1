/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** spawn
*/

#include "../../../include/func_name.h"

void spawn_weapon_2(rpg_t *rpg)
{
    if (rpg->game->in_game->map->status == MAP_OUTSIDE_DISCO &&
    rpg->game->in_game->stuff->stuff_status[SMG] == FALSE) {
        sfSprite_setPosition(rpg->game->in_game->inventory->weapon[SMG],
        put_in_vector2f(rpg->game->in_game->map->pos_map[MAP_OUTSIDE_DISCO].x
        + 1670, rpg->game->in_game->map->pos_map[MAP_OUTSIDE_DISCO].y + 2810));
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->inventory->weapon[SMG], NULL);
    }
    if (rpg->game->in_game->map->status == MAP_OUTSIDE_CDC &&
    rpg->game->in_game->stuff->stuff_status[TAZER] == FALSE) {
        sfSprite_setPosition(rpg->game->in_game->inventory->weapon[TAZER],
        put_in_vector2f(rpg->game->in_game->map->pos_map[MAP_OUTSIDE_CDC].x
        + 1689, rpg->game->in_game->map->pos_map[MAP_OUTSIDE_CDC].y + 2665));
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->inventory->weapon[TAZER], NULL);
    }
}

void spawn_weapons(rpg_t *rpg)
{
    if (rpg->game->in_game->map->status == MAP_INSIDE_POLICE &&
    rpg->game->in_game->stuff->stuff_status[KNIFE] == FALSE) {
        sfSprite_setPosition(rpg->game->in_game->inventory->weapon[KNIFE],
        put_in_vector2f(rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE].x
        + 2044, rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE].y + 2006));
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->inventory->weapon[KNIFE], NULL);
    }
    if (rpg->game->in_game->map->status == MAP_OUTSIDE_POLICE &&
    rpg->game->in_game->stuff->stuff_status[GUN] == FALSE) {
        sfSprite_setPosition(rpg->game->in_game->inventory->weapon[GUN],
        put_in_vector2f(rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].x
        + 1752, rpg->game->in_game->map->pos_map[MAP_OUTSIDE_POLICE].y + 3384));
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->inventory->weapon[GUN], NULL);
    }
}

void spawn_vest(rpg_t *rpg)
{
    if (rpg->game->in_game->map->status == MAP_WARREN &&
    rpg->game->in_game->stuff->stuff_status[BPVEST] == FALSE) {
        sfSprite_setPosition(rpg->game->in_game->inventory->weapon[BPVEST],
        put_in_vector2f(rpg->game->in_game->map->pos_map[MAP_WARREN].x
        + 2362, rpg->game->in_game->map->pos_map[MAP_WARREN].y + 2462));
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->inventory->weapon[BPVEST], NULL);
    }
}

void print_map_loot(rpg_t *rpg)
{
    spawn_weapons(rpg);
    spawn_weapon_2(rpg);
    spawn_vest(rpg);
    weapon_hitbox(rpg);
    weapon_hitbox2(rpg);
    vest_hitbox(rpg);
}