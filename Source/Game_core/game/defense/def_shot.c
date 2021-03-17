/*
** EPITECH PROJECT, 2021
** defense shot by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** def_shot.c
*/

#include "../../../../include/defender.h"
#include <stdio.h>

void range_def(game_t *game, enemy_t *enemy)
{
    defense_t *defense_bis = *(game->defense);
    pirat_data_t *data = *(enemy->data);
    sfFloatRect build;
    sfFloatRect bad_guy;

    for (; defense_bis != NULL; defense_bis = defense_bis->next) {
        data = *(enemy->data);
        build = sfSprite_getGlobalBounds(defense_bis->new_build);
        for (int i = 0;  i < game->nb_spt && data != NULL; data = data->next, i++) {
            bad_guy = sfSprite_getGlobalBounds(data->pirat_walk);
            if ((bad_guy.left < build.left + build.width + 50 && bad_guy.left > build.left - 50) && (bad_guy.top < build.top + build.height + 50 && bad_guy.top > build.top - 50))
                printf("tower = %f, enemy = %f & %f & %i & %i\n", defense_bis->pos.y, data->pos.x, data->pos.y, data->nb_pirat, i);
        }
    }
}
