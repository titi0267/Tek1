/*
** EPITECH PROJECT, 2021
** defense shot by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** def_shot.c
*/

#include "../../../../include/defender.h"
#include <stdio.h>
#include <math.h>

void make_damage(defense_t *defense_bis, pirat_data_t *data, time_t *time)
{
    static float nbr = 0;

    nbr += time->delta_time;
    if (nbr >= defense_bis->shoot_speed) {
        data->life -= defense_bis->damage;
        nbr = 0;
    }
}

void range_def(game_t *game, enemy_t *enemy, time_t *time)
{
    defense_t *defense_bis = *(game->defense);
    pirat_data_t *data = *(enemy->data);
    sfFloatRect build;
    sfFloatRect bad_guy;
    sfVector2f in_range;
    float build_enemy;

    for (; defense_bis != NULL; defense_bis = defense_bis->next) {
        data = *(enemy->data);
        build = sfSprite_getGlobalBounds(defense_bis->new_build);
        for (int i = 0;  i < game->nb_spt && data != NULL; data = data->next, i++) {
            bad_guy = sfSprite_getGlobalBounds(data->pirat_walk);
            in_range.x = (bad_guy.left + (bad_guy.width / 2)) - (build.left + (build.width / 2));
            in_range.y = (bad_guy.top + (bad_guy.height / 2)) - (build.top + (build.height / 2));
            build_enemy = sqrt(pow(in_range.x, 2) + pow(in_range.y, 2));
            if (build_enemy < defense_bis->range) {
                make_damage(defense_bis, data, time);
            }
        }
    }
}
