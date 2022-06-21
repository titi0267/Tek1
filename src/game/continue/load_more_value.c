/*
** EPITECH PROJECT, 2021
** load_value
** File description:
** load_value
*/

#include "../../../include/func_name.h"

static void load_inventory(char *map, rpg_t *rpg)
{
    for (; map[0] != ';'; map++);
    map++;
    rpg->game->in_game->inventory->area_contains[WEAPON] = my_getnbr(map);
    for (; map[0] != ';'; map++);
    map++;
    rpg->game->in_game->inventory->area_contains[VEST] = my_getnbr(map);
    for (int i = 0; i <= TAZER; i++) {
        for (; map[0] != ';'; map++);
        map++;
        rpg->game->in_game->stuff->stuff_status[i] = my_getnbr(map);
    }
    for (; map[0] != ';'; map++);
    map++;
    rpg->game->in_game->stuff->stuff_status[BPVEST] = my_getnbr(map);
    if ( rpg->game->in_game->stuff->stuff_status[BPVEST] == TRUE)
        rpg->game->in_game->inventory->area_contains[VEST] = TRUE;

}

void load_value2(char *map, rpg_t *rpg)
{
    for (; map[0] != ';'; map++);
    map++;
    rpg->game->in_game->stats->level = my_getnbr(map);
    for (; map[0] != ';'; map++);
    map++;
    rpg->game->in_game->stats->xp_value = my_getnbr(map);
    for (; map[0] != ';'; map++);
    map++;
    rpg->game->in_game->stats->player_stats[P_LIFE]->value = my_getnbr(map);
    for (int i = 1; i <= P_ARMOR; i++) {
        for (; map[0] != ';'; map++);
        map++;
        rpg->game->in_game->stats->player_stats[i]->base_value = my_getnbr(map);
    }
    for (; map[0] != ';'; map++);
    map++;
    rpg->game->in_game->phone->notif_index = my_getnbr(map);
    for (; map[0] != ';'; map++);
    map++;
    rpg->game->in_game->game_status = my_getnbr(map);
    load_inventory(map, rpg);
}