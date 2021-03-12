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
        if (data->nb_pirat < 7)
            core->enemy->pirat->rectangle.left = data->nb_pirat * core->enemy->pirat->rectangle.width;
        data = data->next;
    }
}

int moove_pirat(core_t *core)
{
    return (0);
}

int manage_pirat(core_t *core)
{
    pirat_data_t *data = *(core->enemy->data);

    for (int i = 0; i < core->wave->pirate_one; i++) {
        moove_pirat(core);
        sfSprite_setPosition(data->pirat_walk, data->pos);
        sfRenderWindow_drawSprite(core->wnd->window, data->pirat_walk, NULL);
        data = data->next;
    }
    return (0);
}

int feed_spt(core_t *core)
{
    pirat_data_t *data = *(core->enemy->data);
    core->enemy->pirat->pirat_txt = sfTexture_createFromFile("../../../Ressources/perso/Walk/pirate_animated.png", NULL);

    for (int i = 0; i < core->wave->pirate_one; i++)
        sfSprite_setTexture(data->pirat_walk, core->enemy->pirat->pirat_txt, sfFalse);
    return (0);
}