/*
** EPITECH PROJECT, 2021
** save
** File description:
** save
*/

#include "../../../include/func_name.h"

char *save_avance(rpg_t *rpg)
{
    char *avance = my_strcat(my_putnbr(rpg->game->in_game->phone->notif_index)
    , ";");
    avance = my_strcat(avance, my_strcat(
    my_putnbr(rpg->game->in_game->game_status), ";"));

    return (avance);
}

char *save_stats(rpg_t *rpg)
{
    char *stats = my_strcat(my_putnbr(rpg->game->in_game->stats->level), ";");
    stats = my_strcat(stats,
    my_strcat(my_putnbr(rpg->game->in_game->stats->xp_value), ";"));
    for (int i = 0; i <= P_ARMOR; i++)
        stats = my_strcat(stats,
        my_strcat(my_putnbr(rpg->game->in_game->stats->player_stats[i]->value),
        ";"));
    return (stats);
}