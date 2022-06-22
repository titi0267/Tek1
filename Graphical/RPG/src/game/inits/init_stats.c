/*
** EPITECH PROJECT, 2021
** init_phone
** File description:
** init_phone
*/

#include "../../../include/func_name.h"

void init_stats_basic_value(rpg_t *rpg)
{
    rpg->game->in_game->stats->player_stats[P_LIFE]->value = 100;
    rpg->game->in_game->stats->player_stats[P_LIFE]->base_value = 100;
    rpg->game->in_game->stats->player_stats[P_LIFE]->total_value = 100;
    rpg->game->in_game->stats->player_stats[P_DAMAGE]->value = 0;
    rpg->game->in_game->stats->player_stats[P_DAMAGE]->base_value = 5;
    rpg->game->in_game->stats->player_stats[P_DAMAGE]->total_value = 5;
    rpg->game->in_game->stats->player_stats[P_ARMOR]->value = 0;
    rpg->game->in_game->stats->player_stats[P_ARMOR]->base_value = 0;
    rpg->game->in_game->stats->player_stats[P_ARMOR]->total_value = 0;
}

void init_stats_value(rpg_t *rpg)
{
    sfFont *font = sfFont_createFromFile("assets/fonts/aqua.ttf");

    for (int i = 0; i <= P_ARMOR; i++) {
        rpg->game->in_game->stats->player_stats[i]->txt = sfText_create();
        sfText_setString(rpg->game->in_game->stats->player_stats[i]->txt,
        my_putnbr(rpg->game->in_game->stats->player_stats[i]->value));
        sfText_setCharacterSize(rpg->game->in_game->stats->player_stats[i]->txt
        , 30);
        sfText_setFont(rpg->game->in_game->stats->player_stats[i]->txt, font);
    }
    sfText_setPosition(rpg->game->in_game->stats->player_stats[P_LIFE]->txt,
    put_in_vector2f(1432, 449.1));
    sfText_setPosition(rpg->game->in_game->stats->player_stats[P_DAMAGE]->txt,
    put_in_vector2f(1432, 554.7));
    sfText_setPosition(rpg->game->in_game->stats->player_stats[P_ARMOR]->txt,
    put_in_vector2f(1432, 661.5));
}

int malloc_stat_player(rpg_t *rpg)
{
    if ((rpg->game->in_game->stats->player_stats =
    malloc(sizeof(player_stats_t *) * (P_ARMOR + 1))) == NULL)
        return (MALLOC_ERROR);
    for (int i = 0; i <= P_ARMOR; i++) {
        if ((rpg->game->in_game->stats->player_stats[i] =
        malloc(sizeof(player_stats_t))) == NULL)
            return (MALLOC_ERROR);
    }
    return (0);
}