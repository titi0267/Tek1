/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** inventory_manager
*/

#include "../../../include/func_name.h"

void detect_weapon(rpg_t *rpg, sfVector2f mouse)
{
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
}

void detect_inventory_object(rpg_t *rpg)
{
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(rpg->basic->wnd->my_wnd,
    sfMouse_getPositionRenderWindow(rpg->basic->wnd->my_wnd), NULL);

    for (int i = SMG; i != NO_WEAPON; i++) {
        rpg->game->in_game->inventory->glob_pos[i] =
        sfSprite_getGlobalBounds(rpg->game->in_game->inventory->weapon[i]);
    }
    detect_weapon(rpg, mouse);
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

void display_weapons(rpg_t *rpg)
{
    for (int i = SMG; i < NO_WEAPON; i++) {
        if (i == rpg->game->in_game->inventory->selected_item &&
        i != NO_WEAPON - 1)
            i++;
        else if (i == rpg->game->in_game->inventory->selected_item &&
        i == (NO_WEAPON - 1))
            break;
        sfSprite_setPosition(rpg->game->in_game->inventory->weapon[i],
        rpg->game->in_game->inventory->pos_weapon[i]);
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->inventory->weapon[i], NULL);
    }
}
