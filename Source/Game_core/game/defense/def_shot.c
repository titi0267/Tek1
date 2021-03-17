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
    sfFloatRect build = sfSprite_getGlobalBounds(game->defense_bis->new_build);
    sfFloatRect bad_guy = sfSprite_getGlobalBounds(enemy->data_bis->pirat_walk);

    for (; defense_bis != NULL; defense_bis = defense_bis->next) {
        int i = 0;
        for (; data != NULL; data = data->next) {
            if () {

            }
                    printf("tower = %f, enemy = %f\n", game->defense_bis->pos.x, enemy->data_bis->pos.x);
        }
    }
}