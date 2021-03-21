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

void range_def_bis(time_t *time, pirat_data_t *data, defense_t *def, float nb)
{
    if (nb < def->range) {
        make_damage(def, data, time);
    }
}

float range_def_bis_bis(sfVector2f ir, sfFloatRect bg, sfFloatRect b, float be)
{
    ir.x = (bg.left + (bg.width / 2)) - (b.left + (b.width / 2));
    ir.y = (bg.top + (bg.height / 2)) - (b.top + (b.height / 2));
    be = sqrt(pow(ir.x, 2) + pow(ir.y, 2));
    return (be);
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
        for (int i = 0;  i < game->nb_spt && data != NULL;
                                data = data->next, i++) {
            bad_guy = sfSprite_getGlobalBounds(data->pirat_walk);
            build_enemy = range_def_bis_bis(in_range, bad_guy,
                build, build_enemy);
            range_def_bis(time, data, defense_bis, build_enemy);
        }
    }
}