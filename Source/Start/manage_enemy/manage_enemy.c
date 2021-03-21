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
            core->game->money++;
        }
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
    core->game->money += 3;
    core->wave->life_rate++;
    core->wave->nb_wave++;
    core->wave->pirate_one += 5;
    core->wave->wave = FALSE;
    return (0);
}

void manage_enemy(core_t *core)
{
    if (sfSound_getStatus(core->menu->stg->vol->music) == sfStopped)
        sfSound_play(core->menu->stg->vol->music);
    sfRenderWindow_drawSprite(core->wnd->window, core->game->health, NULL);
    sfRenderWindow_drawSprite(core->wnd->window, core->game->deadhead, NULL);
    sfRenderWindow_drawSprite(core->wnd->window, core->game->money_spt, NULL);
    if (core->wave->wave == FALSE)
        feed_enemy(core);
    else
        manage_pirat(core);
    manage_life(core);
    manage_wave(core);
    manage_kill(core);
    init_eco(core);
    manage_sound_game(core);
}