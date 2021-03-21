/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** feel_enemy
*/

#include "../../../include/defender.h"

void feed_enemy_bis(core_t *core, int y)
{
    core->enemy->data_bis = malloc(sizeof(*core->enemy->data_bis));
    core->enemy->data_bis->life = 100 * core->wave->life_rate;
    core->enemy->data_bis->speed = 1;
    core->enemy->data_bis->road = rand() % 2 + 0;
    core->enemy->data_bis->damage = 1;
    core->enemy->data_bis->dead = 0;
    if (core->enemy->data_bis->road == 1) {
        core->enemy->data_bis->pos.x = 1500;
        core->enemy->data_bis->pos.y = 810;
    } else {
        core->enemy->data_bis->pos.x = 1630;
        core->enemy->data_bis->pos.y = 40;
    }
    core->enemy->data_bis->nb_pirat = y;
    core->enemy->data_bis->pirat_walk =
        sfSprite_copy(core->enemy->pirat->pirat_spt);
    core->enemy->data_bis->next = *core->enemy->data;
    *core->enemy->data = core->enemy->data_bis;
    y++;
}

void feed_enemy(core_t *core)
{
    int y = 0;
    *(core->enemy->data) = NULL;

    for (int i = 0; i < core->wave->pirate_one; i++) {
        feed_enemy_bis(core, y);
    }
    core->game->nb_spt = 1;
    rect_pirat(core);
    core->wave->wave = TRUE;
}

void free_linked_list(pirat_data_t *data)
{
    pirat_data_t *data_bis;

   while (data != NULL) {
       data_bis = data;
       data = data->next;
       free(data_bis);
    }
}