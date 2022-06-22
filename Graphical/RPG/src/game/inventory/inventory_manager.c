/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** inventory_manager
*/

#include "../../../include/func_name.h"

void detect_which_weapon_next(inventory_t *ivt, sfVector2f mouse)
{
    if (sfFloatRect_contains(&ivt->glob_pos[KNIFE],
    mouse.x, mouse.y) == sfTrue) {
        ivt->selected_item = KNIFE;
        ivt->click_weapon = TRUE;
        for (int d = 0; d != 18; d++) {
            if (ivt->box_pos[d][0].x < mouse.x && ivt->box_pos[d][0].y < mouse.y
            && ivt->box_pos[d][1].x > mouse.x && ivt->box_pos[d][1].y > mouse.y)
                ivt->is_area_filled[d] = FALSE;
        }
    }
    if (sfFloatRect_contains(&ivt->glob_pos[TAZER],
    mouse.x, mouse.y) == sfTrue) {
        ivt->selected_item = TAZER;
        ivt->click_weapon = TRUE;
        for (int d = 0; d != 18; d++) {
            if (ivt->box_pos[d][0].x < mouse.x && ivt->box_pos[d][0].y < mouse.y
            && ivt->box_pos[d][1].x > mouse.x && ivt->box_pos[d][1].y > mouse.y)
                ivt->is_area_filled[d] = FALSE;
        }
    }
}

void detect_which_weapon(inventory_t *ivt, sfVector2f mouse)
{
    if (sfFloatRect_contains(&ivt->glob_pos[SMG],
    mouse.x, mouse.y) == sfTrue) {
        ivt->selected_item = SMG;
        ivt->click_weapon = TRUE;
        for (int d = 0; d != 18; d++) {
            if (ivt->box_pos[d][0].x < mouse.x && ivt->box_pos[d][0].y < mouse.y
            && ivt->box_pos[d][1].x > mouse.x && ivt->box_pos[d][1].y > mouse.y)
                ivt->is_area_filled[d] = FALSE;
        }
    }
    if (sfFloatRect_contains(&ivt->glob_pos[GUN],
    mouse.x, mouse.y) == sfTrue) {
        ivt->selected_item = GUN;
        ivt->click_weapon = TRUE;
        for (int d = 0; d != 18; d++) {
            if (ivt->box_pos[d][0].x < mouse.x && ivt->box_pos[d][0].y < mouse.y
            && ivt->box_pos[d][1].x > mouse.x && ivt->box_pos[d][1].y > mouse.y)
                ivt->is_area_filled[d] = FALSE;
        }
    }
    detect_which_weapon_next(ivt, mouse);
}

void detect_inventory_object(rpg_t *rpg)
{
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(rpg->basic->wnd->my_wnd,
    sfMouse_getPositionRenderWindow(rpg->basic->wnd->my_wnd), NULL);

    for (int i = SMG; i != NO_WEAPON; i++) {
        rpg->game->in_game->inventory->glob_pos[i] =
        sfSprite_getGlobalBounds(rpg->game->in_game->inventory->weapon[i]);
    }
    detect_which_weapon(rpg->game->in_game->inventory, mouse);
}

void drag(rpg_t *rpg, int selected)
{
    sfVector2f ms_pos = sfRenderWindow_mapPixelToCoords(rpg->basic->wnd->my_wnd,
    sfMouse_getPositionRenderWindow(rpg->basic->wnd->my_wnd), NULL);

    ms_pos.x -= sfSprite_getGlobalBounds(
    rpg->game->in_game->inventory->weapon[selected]).width / 2;
    ms_pos.y -= sfSprite_getGlobalBounds(
    rpg->game->in_game->inventory->weapon[selected]).height / 2;
    sfSprite_setPosition(
    rpg->game->in_game->inventory->weapon[selected], ms_pos);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->game->in_game->inventory->weapon[selected], NULL);
    sfRenderWindow_setMouseCursorVisible(rpg->basic->wnd->my_wnd, sfFalse);
    rpg->game->in_game->inventory->selected_item = selected;
}

void display_loots(rpg_t *rpg)
{
    for (int i = SMG; i < NO_WEAPON; i++) {
        if (i == rpg->game->in_game->inventory->selected_item &&
        i != NO_WEAPON - 1)
            i++;
        else if (i == rpg->game->in_game->inventory->selected_item &&
        i == (NO_WEAPON - 1))
            break;
        if (rpg->game->in_game->stuff->stuff_status[i] == TRUE) {
            sfSprite_setPosition(rpg->game->in_game->inventory->weapon[i],
            rpg->game->in_game->inventory->pos_weapon[i]);
            sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
            rpg->game->in_game->inventory->weapon[i], NULL);
        }
    }
    if (rpg->game->in_game->stuff->stuff_status[BPVEST] == TRUE)
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->inventory->weapon[BPVEST], NULL);
    vaccine_manager(rpg);
}