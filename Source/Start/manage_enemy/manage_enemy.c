/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** manage_enemy
*/

#include "../../../include/defender.h"

void display_list(core_t *core)
{
    pirat_data_t *data_bis = *(core->enemy->data);

    for (; data_bis != NULL; data_bis = data_bis->next)
        my_printf("-> La route est la numéro %i\n", data_bis->road);
    my_printf("-----------------------------------------\n");
}

void feed_enemy(core_t *core)
{
    for (int i = 0; i < core->wave->pirate_one; i++) {
        core->enemy->data_bis = malloc(sizeof(*core->enemy->data_bis));
        core->enemy->data_bis->life = 100;
        core->enemy->data_bis->speed = 1;
        core->enemy->data_bis->road = rand() % 2 + 0;
        core->enemy->data_bis->pos.x = 1500;
        core->enemy->data_bis->pos.y = 600;
        core->enemy->data_bis->pirat_walk = sfSprite_create();
        core->enemy->data_bis->next = *core->enemy->data;
        *core->enemy->data = core->enemy->data_bis;
    }
    feed_spt(core);
    core->wave->wave = TRUE;
}

int check_life(core_t *core)
{
    pirat_data_t *data = *(core->enemy->data);

    for (int i = 0; i < core->wave->pirate_one; i++) {
        if (core->enemy->data_bis->life <= 0)
            return (0);
        data = data->next;
    }
    core->wave->nb_wave++;
    core->wave->pirate_one *= 2;
    core->wave->wave = FALSE;
    return (0);
}

int process_enemy(core_t *core)
{
    return (0);
}

int manage_enemy(core_t *core)
{
    if (core->wave->wave == FALSE)
        feed_enemy(core);
    else
        process_enemy(core);
    return (0);
}