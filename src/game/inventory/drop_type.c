/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** drop_type
*/

#include "../../../include/func_name.h"

void inventory_contains(rpg_t *rpg)
{
    if (rpg->game->in_game->inventory->is_area_filled[15] == FALSE)
        rpg->game->in_game->inventory->area_contains[WEAPON] = NO_WEAPON;
    if (rpg->game->in_game->inventory->is_area_filled[16] == FALSE)
        rpg->game->in_game->inventory->area_contains[AMMO] = NO_BULLET;
    if (rpg->game->in_game->inventory->is_area_filled[17] == FALSE)
        rpg->game->in_game->inventory->area_contains[VEST] = NO_VEST;
}

void drop_weapons(rpg_t *rpg)
{
    if ((rpg->game->in_game->inventory->selected_item >= SMG &&
    rpg->game->in_game->inventory->selected_item < NO_WEAPON) &&
    ((rpg->basic->cnf->mouse.x) >= adapt_x(rpg,
    rpg->game->in_game->inventory->box_pos[15][0].x)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg,
    rpg->game->in_game->inventory->box_pos[15][0].y)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg,
    rpg->game->in_game->inventory->box_pos[15][1].x)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg,
    rpg->game->in_game->inventory->box_pos[15][1].y)) &&
    rpg->game->in_game->inventory->is_area_filled[15] == FALSE) {
        rpg->game->in_game->inventory->pos_weapon
        [rpg->game->in_game->inventory->selected_item] = put_in_vector2f(
        (float)rpg->game->in_game->inventory->box_pos[15][0].x,
        (float)rpg->game->in_game->inventory->box_pos[15][0].y);
        rpg->game->in_game->inventory->area_contains[WEAPON] =
        rpg->game->in_game->inventory->selected_item;
        rpg->game->in_game->inventory->is_area_filled[15] = TRUE;
    }
}

void drop_bullets(rpg_t *rpg)
{
    if ((rpg->game->in_game->inventory->selected_item >= BULLET_1 &&
    rpg->game->in_game->inventory->selected_item < NO_BULLET) &&
    ((rpg->basic->cnf->mouse.x) >= adapt_x(rpg,
    rpg->game->in_game->inventory->box_pos[16][0].x)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg,
    rpg->game->in_game->inventory->box_pos[16][0].y)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg,
    rpg->game->in_game->inventory->box_pos[16][1].x)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg,
    rpg->game->in_game->inventory->box_pos[16][1].y)) &&
    rpg->game->in_game->inventory->is_area_filled[16] == FALSE) {
        rpg->game->in_game->inventory->pos_weapon
        [rpg->game->in_game->inventory->selected_item] = put_in_vector2f(
        (float)rpg->game->in_game->inventory->box_pos[16][0].x,
        (float)rpg->game->in_game->inventory->box_pos[16][0].y);
        rpg->game->in_game->inventory->area_contains[AMMO] =
        rpg->game->in_game->inventory->selected_item;
        rpg->game->in_game->inventory->is_area_filled[16] = TRUE;
    }
}

void drop_bullet_proof(rpg_t *rpg)
{
    if ((rpg->game->in_game->inventory->selected_item == BPVEST) &&
    ((rpg->basic->cnf->mouse.x) >= adapt_x(rpg,
    rpg->game->in_game->inventory->box_pos[17][0].x)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg,
    rpg->game->in_game->inventory->box_pos[17][0].y)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg,
    rpg->game->in_game->inventory->box_pos[17][1].x)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg,
    rpg->game->in_game->inventory->box_pos[17][1].y)) &&
    rpg->game->in_game->inventory->is_area_filled[17] == FALSE) {
        rpg->game->in_game->inventory->pos_weapon
        [rpg->game->in_game->inventory->selected_item] = put_in_vector2f(
        (float)rpg->game->in_game->inventory->box_pos[17][0].x,
        (float)rpg->game->in_game->inventory->box_pos[17][0].y);
        rpg->game->in_game->inventory->area_contains[VEST] =
        rpg->game->in_game->inventory->selected_item;
    rpg->game->in_game->inventory->is_area_filled[17] = TRUE;
    }
}

void drop_all_boxes(rpg_t *rpg)
{
    for (int i = 0; i <= 14; i++) {
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg,
        rpg->game->in_game->inventory->box_pos[i][0].x)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg,
        rpg->game->in_game->inventory->box_pos[i][0].y)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg,
        rpg->game->in_game->inventory->box_pos[i][1].x)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg,
        rpg->game->in_game->inventory->box_pos[i][1].y)) &&
        rpg->game->in_game->inventory->is_area_filled[i] == FALSE) {
            rpg->game->in_game->inventory->pos_weapon
            [rpg->game->in_game->inventory->selected_item] = put_in_vector2f(
            (float)rpg->game->in_game->inventory->box_pos[i][0].x,
            (float)rpg->game->in_game->inventory->box_pos[i][0].y);
            rpg->game->in_game->inventory->is_area_filled[i] = TRUE;
        }
    }
    drop_weapons(rpg);
    drop_bullets(rpg);
    drop_bullet_proof(rpg);
    inventory_contains(rpg);
}