/*
** EPITECH PROJECT, 2021
** save
** File description:
** save
*/

#include "../../../include/func_name.h"

char *save_avance(rpg_t *rpg)
{
    char *avance = my_strcat(my_putnbr(rpg->game->in_game->phone->notif_index),
    ";");
    avance = my_strcat(avance, my_strcat(
    my_putnbr(rpg->game->in_game->game_status), ";"));

    return (avance);
}

char *save_stats(rpg_t *rpg)
{
    char *stats = my_strcat(my_putnbr(rpg->game->in_game->stats->level), ";");
    stats = my_strcat(stats,
    my_strcat(my_putnbr(rpg->game->in_game->stats->xp_value), ";"));
    stats = my_strcat(stats,
        my_strcat(my_putnbr(rpg->game->in_game->stats->player_stats[P_LIFE]->
        value), ";"));
    for (int i = 1; i <= P_ARMOR; i++)
        stats = my_strcat(stats,
        my_strcat(my_putnbr(rpg->game->in_game->stats->player_stats[i]->
        base_value), ";"));
    return (stats);
}

char *save_invent(rpg_t *rpg)
{
    char *invent = my_strcat(my_putnbr(rpg->game->in_game->inventory->
    area_contains[WEAPON]), ";");
    invent = my_strcat(invent,
    my_strcat(my_putnbr(rpg->game->in_game->inventory->
    area_contains[VEST]), ";"));
    for (int i = 0; i <= TAZER; i++)
        invent = my_strcat(invent,
        my_strcat(my_putnbr(rpg->game->in_game->stuff->stuff_status[i]), ";"));
    invent = my_strcat(invent,
    my_strcat(my_putnbr(rpg->game->in_game->stuff->stuff_status[BPVEST]), ";"));
    return (invent);
}