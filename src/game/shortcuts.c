/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** shortcuts
*/

#include "../../include/func_name.h"

void key_event_game(rpg_t *rpg)
{
    if ((rpg->basic->evt->event.type == sfEvtTextEntered) &&
    (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[INVENTORY]->text[0]
    && rpg->basic->cnf->clk->time_keyboard >= 0.2)) {
        if (rpg->game->in_game->inventory->shortcut_it == INVENTORY_OFF) {
            rpg->menu->status = ON_INVENTORY;
            rpg->game->in_game->inventory->shortcut_it = INVENTORY_ON;
            rpg->basic->cnf->clk->time_keyboard = 0;
            return;
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
        rpg->menu->status = ON_EXIT;
}

void key_event_inventory(rpg_t *rpg)
{
    if ((rpg->basic->evt->event.type == sfEvtTextEntered) &&
    ((unsigned int)rpg->menu->stg->key_bnd->control[INVENTORY]->text[0]
    && rpg->basic->cnf->clk->time_keyboard >= 0.2)) {
        if (rpg->game->in_game->inventory->shortcut_it == INVENTORY_ON) {
            sfRenderWindow_setMouseCursorVisible(rpg->basic->wnd->my_wnd,
            sfTrue);
            rpg->menu->status = ON_GAME;
            rpg->game->in_game->inventory->shortcut_it = INVENTORY_OFF;
            rpg->basic->cnf->clk->time_keyboard = 0;
            return;
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
        rpg->menu->status = ON_GAME;
}