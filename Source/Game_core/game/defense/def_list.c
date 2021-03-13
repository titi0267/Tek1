/*
** EPITECH PROJECT, 2021
** defense list by TImothy CONIEL & Tristan HORTOULLE
** File description:
** def_list.c
*/

#include "../../../../include/defender.h"

void add_def(game_t *game, window_t *wnd)
{
    static int i = 0;

    if (game->tower->tower_release == 2 && i == 0) {
        game->defense_bis = malloc(sizeof(*game->defense_bis));
        game->defense_bis->damage = 20;
        game->defense_bis->shoot_speed = 0.1;
        game->defense_bis->range = 5;
        game->defense_bis->pos.x = 300;
        game->defense_bis->pos.y = 700;
        game->defense_bis->new_build = sfSprite_copy(game->tower->ice_tower_spt);
        sfSprite_setPosition(game->defense_bis->new_build,
                            game->defense_bis->pos);
        game->defense_bis->next = *game->defense;
        *game->defense = game->defense_bis;
        i++;
    }
    if (i > 0) {
        sfRenderWindow_drawSprite(wnd->window, game->defense_bis->new_build, NULL);
        my_printf("damage = %i\n", game->defense_bis->damage);
        my_printf("range = %i\n", game->defense_bis->range);
    }
}