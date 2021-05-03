/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** drop_type
*/

#include "../../../include/func_name.h"

void drop_weapons(rpg_t *rpg)
{
    if ((rpg->game->in_game->inventory->selected_item >= SMG &&
    rpg->game->in_game->inventory->selected_item < NO_WEAPON) &&
    ((rpg->basic->cnf->mouse.x) >= adapt_x(rpg,
    rpg->game->in_game->inventory->box_pos[24][0].x)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg,
    rpg->game->in_game->inventory->box_pos[24][0].y)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg,
    rpg->game->in_game->inventory->box_pos[24][1].x)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg,
    rpg->game->in_game->inventory->box_pos[24][1].y))) {
        rpg->game->in_game->inventory->pos_weapon
        [rpg->game->in_game->inventory->selected_item] = put_in_vector2f(
        (float)rpg->game->in_game->inventory->box_pos[24][0].x,
        (float)rpg->game->in_game->inventory->box_pos[24][0].y);
    }
}

void drop_bullets(rpg_t *rpg)
{
    if ((rpg->game->in_game->inventory->selected_item >= BULLET_1 &&
    rpg->game->in_game->inventory->selected_item < NO_BULLET) &&
    ((rpg->basic->cnf->mouse.x) >= adapt_x(rpg,
    rpg->game->in_game->inventory->box_pos[25][0].x)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg,
    rpg->game->in_game->inventory->box_pos[25][0].y)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg,
    rpg->game->in_game->inventory->box_pos[25][1].x)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg,
    rpg->game->in_game->inventory->box_pos[25][1].y))) {
        rpg->game->in_game->inventory->pos_weapon
        [rpg->game->in_game->inventory->selected_item] = put_in_vector2f(
        (float)rpg->game->in_game->inventory->box_pos[25][0].x,
        (float)rpg->game->in_game->inventory->box_pos[25][0].y);
    }
}

void drop_bullet_proof(rpg_t *rpg)
{
    if ((rpg->game->in_game->inventory->selected_item >= BULLET_1 && //Change with bullet proof vest
    rpg->game->in_game->inventory->selected_item < NO_BULLET) &&
    ((rpg->basic->cnf->mouse.x) >= adapt_x(rpg,
    rpg->game->in_game->inventory->box_pos[26][0].x)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg,
    rpg->game->in_game->inventory->box_pos[26][0].y)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg,
    rpg->game->in_game->inventory->box_pos[26][1].x)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg,
    rpg->game->in_game->inventory->box_pos[26][1].y))) {
        rpg->game->in_game->inventory->pos_weapon
        [rpg->game->in_game->inventory->selected_item] = put_in_vector2f(
        (float)rpg->game->in_game->inventory->box_pos[26][0].x,
        (float)rpg->game->in_game->inventory->box_pos[26][0].y);
    }

}

void drop_all_boxes(rpg_t *rpg)
{
    for (int i = 0; i <= 23; i++) {
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg,
        rpg->game->in_game->inventory->box_pos[i][0].x)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg,
        rpg->game->in_game->inventory->box_pos[i][0].y)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg,
        rpg->game->in_game->inventory->box_pos[i][1].x)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg,
        rpg->game->in_game->inventory->box_pos[i][1].y))) {
            rpg->game->in_game->inventory->pos_weapon
            [rpg->game->in_game->inventory->selected_item] = put_in_vector2f(
            (float)rpg->game->in_game->inventory->box_pos[i][0].x,
            (float)rpg->game->in_game->inventory->box_pos[i][0].y);
        }
    }
    drop_weapons(rpg);
    drop_bullets(rpg);
    drop_bullet_proof(rpg);
}