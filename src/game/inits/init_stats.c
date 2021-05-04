/*
** EPITECH PROJECT, 2021
** init_phone
** File description:
** init_phone
*/

#include "../../../include/func_name.h"

void init_stats_value(rpg_t *rpg)
{
    sfFont *font = sfFont_createFromFile("assets/fonts/aqua.ttf");
    rpg->game->in_game->stats->player_stats[P_LIFE]->value = 100;
    rpg->game->in_game->stats->player_stats[P_DAMAGE]->value = 5;
    rpg->game->in_game->stats->player_stats[P_ARMOR]->value = 0;

    for (int i = 0; i <= P_ARMOR; i++) {
        rpg->game->in_game->stats->player_stats[i]->txt = sfText_create();
        sfText_setString(rpg->game->in_game->stats->player_stats[i]->txt,
        my_putnbr(rpg->game->in_game->stats->player_stats[i]->value));
        sfText_setCharacterSize(rpg->game->in_game->stats->player_stats[i]->txt
        , 30);
        sfText_setFont(rpg->game->in_game->stats->player_stats[i]->txt, font);
    }
    sfText_setPosition(rpg->game->in_game->stats->player_stats[P_LIFE]->txt,
    put_in_vector2f(1432, 432));
    sfText_setPosition(rpg->game->in_game->stats->player_stats[P_DAMAGE]->txt,
    put_in_vector2f(1432, 538));
    sfText_setPosition(rpg->game->in_game->stats->player_stats[P_ARMOR]->txt,
    put_in_vector2f(1432, 645));
}

int malloc_stat_player(rpg_t *rpg)
{
    if ((rpg->game->in_game->stats->player_stats =
    malloc(sizeof(player_stats_t *) * (P_ARMOR + 1))) == NULL)
        return (MALLOC_ERROR);
    for (int i = 0; i <= P_ARMOR; i++) {
        if ((rpg->game->in_game->stats->player_stats[i] =
        malloc(sizeof(player_stats_t))) == NULL)
            return(MALLOC_ERROR);
    }
    return (0);
}