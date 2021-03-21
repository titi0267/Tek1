/*
** EPITECH PROJECT, 2021
** defense list by TImothy CONIEL & Tristan HORTOULLE
** File description:
** def_list.c
*/

#include "../../../../include/defender.h"

void tower_array(game_t *game)
{
    game->tower->def_list = malloc(sizeof(sfSprite *) * 10);

    game->tower->def_list[0] = sfSprite_copy(game->tower->ice_tower_spt);
    game->tower->def_list[1] = sfSprite_copy(game->tower->arrow_tower_spt);
    game->tower->def_list[2] = sfSprite_copy(game->tower->wiz_tower_spt);
    game->init_def = FALSE;
}

void print_def(game_t *game, window_t *wnd)
{
    defense_t *defense_bis = *(game->defense);

    for (; defense_bis != NULL; defense_bis = defense_bis->next) {
        sfRenderWindow_drawSprite(wnd->window, defense_bis->new_build, NULL);
    }
}

void add_def(game_t *game)
{
    game->defense_bis = malloc(sizeof(*game->defense_bis));
    ice_def(game);
    archer_def(game);
    wiz_def(game);
    game->defense_bis->pos.x = game->tower->transmit_pos.x;
    game->defense_bis->pos.y = game->tower->transmit_pos.y;
    game->defense_bis->new_build = sfSprite_copy(
                            game->tower->def_list[game->tower->wich_defense]);
    sfSprite_setPosition(game->defense_bis->new_build,
                        game->defense_bis->pos);
    game->defense_bis->next = *game->defense;
    *game->defense = game->defense_bis;
    game->tower->tower_release = FALSE;
    game->init_def = TRUE;
}
