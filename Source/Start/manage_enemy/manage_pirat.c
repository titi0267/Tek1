/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** manage_pirat
*/

#include "../../../include/defender.h"

void rect_pirat(core_t *core)
{
    core->enemy->pirat->rectangle.top = 0;
    core->enemy->pirat->rectangle.left = 0;
    core->enemy->pirat->rectangle.width = 189.28;
    core->enemy->pirat->rectangle.height = 216;
}

void moove_rect_bis(core_t *core, pirat_data_t *data)
{
    if (data->nb_pirat < 7)
        core->enemy->pirat->rectangle.left = data->nb_pirat * core->enemy->pirat->rectangle.width;
    else
        data->nb_pirat = 0;
}

void moove_rect(core_t *core)
{
    pirat_data_t *data = *(core->enemy->data);
    static float nbr = 0;

    nbr += core->time->delta_time;
    if (nbr > 0.5) {
        for (int i = 0; i < core->wave->pirate_one; i++) {
            moove_rect_bis(core, data);
            data->nb_pirat++;
            data = data->next;
        }
        nbr = 0;
    }
}

int manage_pirat(core_t *core)
{
    pirat_data_t *data_bis = *(core->enemy->data);
    sfVector2f scale = {0.37, 0.37};
    static float nbr = 0;

    for (int i = 0; i < core->game->nb_spt && core->enemy->data_bis != NULL; data_bis = data_bis->next, i++)
        moove_pirat(core, data_bis);
    if (core->menu->pause_on == FALSE) {
        nbr += core->time->delta_time;
        check_wave(core);
        if (nbr >= 2 && core->game->nb_spt < core->wave->pirate_one) {
            core->game->nb_spt++;
            nbr = 0;
        }
    }
    return (0);
}

void feed_spt(core_t *core)
{
    core->enemy->pirat->pirat_txt = sfTexture_createFromFile(
                            "Ressources/perso/Walk/pirate_animated.png", NULL);
    core->enemy->pirat->pirat_spt = sfSprite_create();

    sfSprite_setTexture(core->enemy->pirat->pirat_spt,
                        core->enemy->pirat->pirat_txt, sfFalse);
}