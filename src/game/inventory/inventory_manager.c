/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** inventory_manager.c
*/

#include "../../../include/func_name.h"
// ARME = 370.5 x 366.5        -       446.5 x 442.5

void detect_weapon(rpg_t *rpg)
{
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(rpg->basic->wnd->my_wnd,
    sfMouse_getPositionRenderWindow(rpg->basic->wnd->my_wnd), NULL);

    for (int i = SMG; i != NO_WEAPON; i++) {
        rpg->game->in_game->inventory->glob_pos[i] =
        sfSprite_getGlobalBounds(rpg->game->in_game->inventory->weapon[i]);
    }
    if (sfFloatRect_contains(&rpg->game->in_game->inventory->glob_pos[SMG],
    mouse.x, mouse.y) == sfTrue) {
        rpg->game->in_game->inventory->selected_item = SMG;
        rpg->game->in_game->inventory->click_weapon = TRUE;
    }
    if (sfFloatRect_contains(&rpg->game->in_game->inventory->glob_pos[GUN],
    mouse.x, mouse.y) == sfTrue) {
        rpg->game->in_game->inventory->selected_item = GUN;
        rpg->game->in_game->inventory->click_weapon = TRUE;
    }
    if (sfFloatRect_contains(&rpg->game->in_game->inventory->glob_pos[KNIFE],
    mouse.x, mouse.y) == sfTrue) {
        rpg->game->in_game->inventory->selected_item = KNIFE;
        rpg->game->in_game->inventory->click_weapon = TRUE;
    }
    if (sfFloatRect_contains(&rpg->game->in_game->inventory->glob_pos[TAZER],
    mouse.x, mouse.y) == sfTrue) {
        rpg->game->in_game->inventory->selected_item = TAZER;
        rpg->game->in_game->inventory->click_weapon = TRUE;
    }
    /*if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue &&
    rpg->game->in_game->inventory->selected_item == NO_WEAPON) {*/
        /*if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 825.5)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 421.5)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 901.5)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 497.5))) {
            rpg->game->in_game->inventory->selected_item = SMG;
        }
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 916.5)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 421.5)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 992.5)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 497.5))) {
            rpg->game->in_game->inventory->selected_item = KNIFE;
        }
        detect_weapon2(rpg);
    }*/
}