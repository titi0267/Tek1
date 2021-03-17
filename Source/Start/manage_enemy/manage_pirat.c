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

void moove_rect(core_t *core)
{
    sfClock *clock;
    sfTime time;
    float number = 0;
    pirat_data_t *data = *(core->enemy->data);

    clock = sfClock_create();
    while (number < 0.1) {
        time = sfClock_getElapsedTime(clock);
        number = time.microseconds / 500000.0;
    }
    for (int i = 0; i < core->wave->pirate_one; i++) {
        if (data->nb_pirat < 7) {
            core->enemy->pirat->rectangle.left = data->nb_pirat * core->enemy->pirat->rectangle.width;
        } else
            core->enemy->pirat->rectangle.left = 0;
        data->nb_pirat++;
        data = data->next;
    }
}

int manage_pirat(core_t *core)
{
    pirat_data_t *data_bis = *(core->enemy->data);
    sfVector2f scale = {0.37, 0.37};
    static float nbr = 0;

    nbr += core->time->delta_time;
    for (int i = 0; i < core->game->nb_spt && core->enemy->data_bis != NULL; data_bis = data_bis->next, i++) {
        moove_pirat(core);
        range_def(core->game, core->enemy);
        sfSprite_setPosition(data_bis->pirat_walk, data_bis->pos);
        sfSprite_setTextureRect(data_bis->pirat_walk, core->enemy->pirat->rectangle);
        sfSprite_setScale(data_bis->pirat_walk, scale);
        sfRenderWindow_drawSprite(core->wnd->window, data_bis->pirat_walk, NULL);
    }
    if (nbr >= 2 && core->game->nb_spt < core->wave->pirate_one) {
        core->game->nb_spt++;
        nbr = 0;
    }
    return (0);
}

int feed_spt(core_t *core)
{
    pirat_data_t *data_bis = *(core->enemy->data);
    core->enemy->pirat->pirat_txt = sfTexture_createFromFile(
                            "Ressources/perso/Walk/pirate_animated.png", NULL);

    for (int i = 0; data_bis != NULL; data_bis = data_bis->next)
        sfSprite_setTexture(data_bis->pirat_walk, core->enemy->pirat->pirat_txt, sfTrue);
    return (0);
}