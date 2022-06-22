/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** phone
*/

#include "../../../include/func_name.h"

static void wait_notif(rpg_t *rpg)
{
    static float time = 0;

    if (sfSound_getStatus(rpg->game->in_game->phone->alarm)
    == sfStopped)
        if (rpg->game->in_game->phone->phone_status == 0)
            time += rpg->basic->cnf->clk->time_loop;
    if (rpg->game->in_game->phone->phone_status == 2)
        time = 0;
    if (time >= 2) {
        rpg->game->in_game->phone->notif_index++;
        rpg->game->in_game->phone->phone_status = 1;
        rpg->game->in_game->phone->notif_bool = FALSE;
        time = 0;
    }
}

void print_phone(rpg_t *rpg)
{
    switch (rpg->game->in_game->phone->phone_status)
    {
    case 0:
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->phone->phone_icone, NULL);
        break;
    case 1:
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->phone->phone_icone, NULL);
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->phone->phone_notif, NULL);
        break;
    case 2:
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->phone->phone
        [rpg->game->in_game->phone->notif_index], NULL);
    }
}

static void check_phone(rpg_t *rpg)
{
    static float nbr = 0;

    nbr += rpg->basic->cnf->clk->time_loop;
    if (((rpg->game->in_game->phone->phone_status == 2) &&
    (rpg->basic->evt->event.type == sfEvtMouseButtonPressed) &&
    (rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1461)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 131)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1478)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 156)) && nbr >= 0.2) {
        rpg->game->in_game->phone->phone_status = 0;
        nbr = 0;
    }
}

void toggle_phone(rpg_t *rpg)
{
    static float nbr = 0;

    nbr += rpg->basic->cnf->clk->time_loop;
    if ((((rpg->basic->evt->event.type == sfEvtTextEntered) &&
    (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[CELLPHONE]->text[0]))
    || ((rpg->game->in_game->phone->phone_status == 0 ||
    rpg->game->in_game->phone->phone_status == 1) &&
    ((rpg->basic->evt->event.type == sfEvtMouseButtonPressed) &&
    (rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1794.9)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 838)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1907)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 1005)))) && nbr >= 0.2) {
        rpg->game->in_game->phone->phone_status =
        (rpg->game->in_game->phone->phone_status == 0 ||
        rpg->game->in_game->phone->phone_status == 1) ? 2 : 0;
        nbr = 0;
    }
    check_phone(rpg);
}

void phone_main(rpg_t *rpg)
{
    toggle_phone(rpg);
    print_phone(rpg);
    if (rpg->game->in_game->phone->notif_index ==
    rpg->game->in_game->phone->notif_prev)
        wait_notif(rpg);
    if (rpg->game->in_game->phone->notif_bool == FALSE &&
    rpg->game->in_game->game_status != GM_INCOMMING_CALL &&
    rpg->game->in_game->game_status != GM_CALL) {
        sfSound_play(rpg->game->in_game->phone->notif_sound);
        rpg->game->in_game->phone->notif_bool = TRUE;
    }
}