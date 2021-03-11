/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** manage_enemy
*/

#include "../../../include/defender.h"

int display_list(core_t *core)
{
    pirat_data_t *data_bis = *(core->enemy->data);

    for (; data_bis != NULL; data_bis = data_bis->next)
        my_printf("-> La route est la numéro %i\n", data_bis->road);
    my_printf("-----------------------------------------\n");
}

int feed_enemy(core_t *core)
{
    static int i = 0;

    for (; i < core->wave->pirate_one; i++) {
        core->enemy->data_bis = malloc(sizeof(*core->enemy->data_bis));
        core->enemy->data_bis->life = 100;
        core->enemy->data_bis->speed = 1;
        core->enemy->data_bis->road = rand() % 2 + 0;
        core->enemy->data_bis->pos.x = 1500;
        core->enemy->data_bis->pos.y = 600;
        core->enemy->data_bis->next = *core->enemy->data;
        *core->enemy->data = core->enemy->data_bis;
    }
}

int manage_enemy(core_t *core)
{
    feed_enemy(core);
    return (0);
}