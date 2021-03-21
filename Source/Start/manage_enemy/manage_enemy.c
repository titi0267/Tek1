/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** manage_enemy
*/

#include "../../../include/defender.h"

void check_life(core_t *core)
{
    pirat_data_t *data = *(core->enemy->data);

    for (; data != NULL; data = data->next) {
        if (data->life <= 0 && data->dead == 0) {
            sfSound_play(core->menu->stg->vol->kill);
            data->dead = 1;
            core->wave->kill++;
        }
    }
}

void feed_enemy(core_t *core)
{
    int y = 0;
    *(core->enemy->data) = NULL;

    for (int i = 0; i < core->wave->pirate_one; i++) {
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
        core->enemy->data_bis->pirat_walk = sfSprite_create();
        core->enemy->data_bis->next = *core->enemy->data;
        *core->enemy->data = core->enemy->data_bis;
        y++;
    }
    core->game->nb_spt = 1;
    rect_pirat(core);
    feed_spt(core);
    core->wave->wave = TRUE;
}

int free_linked_list(pirat_data_t *data)
{
    pirat_data_t *data_bis;

   while (data != NULL)
    {
       data_bis = data;
       data = data->next;
       free(data_bis);
    }
}

int check_wave(core_t *core)
{
    pirat_data_t *data = *(core->enemy->data);
    pirat_data_t *data_bis = *(core->enemy->data);
    int tmp = 0;

    for (int i = 0; i < core->wave->pirate_one; i++) {
        if (data->dead == 1)
            tmp += 1;
        data = data->next;
    }
    if (tmp != core->wave->pirate_one)
        return (0);
    sfSound_play(core->menu->stg->vol->nxt_lvl);
    free_linked_list(data_bis);
    core->wave->life_rate++;
    core->wave->nb_wave++;
    core->wave->pirate_one += 5;
    core->wave->wave = FALSE;
    return (0);
}

void manage_enemy(core_t *core)
{
    if (core->wave->wave == FALSE)
        feed_enemy(core);
    else
        manage_pirat(core);
    manage_life(core);
    manage_wave(core);
    manage_kill(core);
}