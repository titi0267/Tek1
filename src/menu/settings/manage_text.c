/*
** EPITECH PROJECT, 2021
** manage_text
** File description:
** manage_text
*/

#include "../../../include/func_name.h"

static void update_text(int nbr, rpg_t *rpg)
{
    for (int i = 0; i <= QUADCOPTER; i++) {
        if ((rpg->basic->evt->event.type == sfEvtTextEntered) &&
        (rpg->menu->stg->key_bnd->control[i]->text[0] ==
        (char)rpg->basic->evt->event.text.unicode))
            return;
    }
    rpg->menu->stg->key_bnd->control[nbr]->text[0] =
    rpg->basic->evt->event.text.unicode;
    rpg->menu->stg->key_bnd->control[nbr]->text[1] = '\0';
    return;
}

void change_control(rpg_t *rpg)
{
    if (rpg->basic->evt->event.type == sfEvtTextEntered) {
        if ((rpg->basic->evt->event.type == sfEvtTextEntered) &&
        (rpg->basic->evt->event.text.unicode >= 97 &&
        rpg->basic->evt->event.text.unicode <= 122)
        && rpg->basic->cnf->clk->time_shortcut >= 0.15 &&
        rpg->menu->stg->key_bnd->box_clicked != -1) {
            update_text(rpg->menu->stg->key_bnd->box_clicked, rpg);
            sfText_setString(rpg->menu->stg->key_bnd->control
            [rpg->menu->stg->key_bnd->box_clicked]->box, rpg->menu->stg->
            key_bnd->control[rpg->menu->stg->key_bnd->box_clicked]->text);
            rpg->basic->cnf->clk->time_shortcut = 0;
            rpg->menu->stg->key_bnd->box_clicked = -1;
        }
    }
}

void reload_control(setting_t *stg)
{
    for (int i = 0; i <= QUADCOPTER; i++) {
        sfText_setString(stg->key_bnd->control[i]->box,
        stg->key_bnd->control[i]->text);
    }
}