/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** manage_enemy
*/

#include "../../../include/struct.h"

int display_list(pirat_data_t **data)
{
    pirat_data_t *data_bis = *data;

    for (; data_bis != NULL; data_bis = data_bis->next)
        printf("-> La route est la numéro %i\n", data_bis->road);
}

int feed_enemy(core_t *core)
{
    pirat_data_t **data
    pirat_data_t *data_bis;

    for (int i = 0; i < core->wave->pirate_one; i++) {
        data_bis = malloc(sizeof(*data_bis));
        data->life = 100;
        data->speed = 1;
        data->road = rand() % 2 + 0;
        data->x = 1500;
        data->y = 600;
        data->pos = {x, y};
        data_bis->next = *data;
        *data = data_bis;
    }
    display_list(data);
}

int manage_enemy(core_t *core)
{
    feed_enemy(core);
    return (0);
}