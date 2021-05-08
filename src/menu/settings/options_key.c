/*
** EPITECH PROJECT, 2021
** key
** File description:
** key
*/

#include "../../../include/func_name.h"

void text_hitbox3(rpg_t *rpg)
{
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1490)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 667.4)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1603.4)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 705.9)))
            rpg->menu->stg->key_bnd->box_clicked = 6;
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1490)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 741.4)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1603.4)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 770.9)))
            rpg->menu->stg->key_bnd->box_clicked = 7;
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1490)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 805.2)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1603.4)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 834.7)))
            rpg->menu->stg->key_bnd->box_clicked = 8;
}

void text_hitbox2(rpg_t *rpg)
{
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1490)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 437.2)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1603.4)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 466.7)))
            rpg->menu->stg->key_bnd->box_clicked = 3;
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1490)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 505.7)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1603.4)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 535.2)))
            rpg->menu->stg->key_bnd->box_clicked = 4;
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1490)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 591.1)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1603.4)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 620.6)))
            rpg->menu->stg->key_bnd->box_clicked = 5;
    text_hitbox3(rpg);
}

void text_hitbox(rpg_t *rpg)
{
    if (rpg->basic->evt->event.type == sfEvtMouseButtonPressed) {
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1490)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 242.2)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1603.4)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 271.7)))
            rpg->menu->stg->key_bnd->box_clicked = 0;
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1490)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 307.2)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1603.4)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 336.7)))
            rpg->menu->stg->key_bnd->box_clicked = 1;
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1490)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 372.2)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1603.4)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 401.7)))
            rpg->menu->stg->key_bnd->box_clicked = 2;
        text_hitbox2(rpg);
    }
}

void reset_key(rpg_t *rpg)
{
    if (rpg->basic->evt->event.type == sfEvtMouseButtonPressed) {
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1490)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 156.8)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1603.4)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 186.3))) {
            rpg->menu->stg->key_bnd->control[UP]->text[0] = 'z';
            rpg->menu->stg->key_bnd->control[DOWN]->text[0] = 's';
            rpg->menu->stg->key_bnd->control[LEFT]->text[0] = 'q';
            rpg->menu->stg->key_bnd->control[RIGHT]->text[0] = 'd';
            rpg->menu->stg->key_bnd->control[RUN]->text[0] = 'r';
            rpg->menu->stg->key_bnd->control[INVENTORY]->text[0] = 'e';
            rpg->menu->stg->key_bnd->control[CELLPHONE]->text[0] = 't';
            rpg->menu->stg->key_bnd->control[CAR]->text[0] = 'c';
            rpg->menu->stg->key_bnd->control[QUADCOPTER]->text[0] = 'x';
            reload_control(rpg->menu->stg);
        }
    }
}

void manage_key(rpg_t *rpg)
{
    for (int i = 0; i <= QUADCOPTER; i++) {
        sfRenderWindow_drawText(rpg->basic->wnd->my_wnd,
        rpg->menu->stg->key_bnd->control[i]->box, NULL);
    }
    reset_key(rpg);
    text_hitbox(rpg);
    change_control(rpg);
}