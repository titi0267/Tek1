/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** display_inventory.c
*/

#include "../../../include/func_name.h"
// ARME = 370.5 x 366.5        -       446.5 x 442.5
// MUNITION = 370.5 x 456.833          -           446.5 x 532.833
// GILET PAR BALLES = 370.5 x 637.5            -           446.5 x 713.5

// CASE POUR POSER DES ARMES : ((825.5,421.5), (901.5,497.5))
// - ((916.5,421.5) , (992.5, 497.5))
// - ((1007.5, 421.5) , (1083.5, 497.5))
// - ((1098.5, 421.5) , (1174.5, 497.5))

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
    sfRenderWindow_setMouseCursorVisible(rpg->basic->wnd->my_wnd, FALSE);
    rpg->game->in_game->inventory->is_item_selected = TRUE;
    rpg->game->in_game->inventory->selected_item = selected;
}

void display_weapons(rpg_t *rpg)
{
    for (int i = SMG; i < NO_WEAPON; i++) {
        sfSprite_setPosition(rpg->game->in_game->inventory->weapon[i],
        rpg->game->in_game->inventory->pos_weapon[i]);
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->inventory->weapon[i], NULL);
    }
}

void drop_weapon(rpg_t *rpg, int weapon)
{
    sfRenderWindow_setMouseCursorVisible(rpg->basic->wnd->my_wnd, TRUE);
    sfSprite_setPosition(rpg->game->in_game->inventory->weapon[weapon],
    rpg->game->in_game->inventory->pos_storage[WEAPON]);
    rpg->game->in_game->inventory->is_area_filled[WEAPON] = weapon;
    rpg->game->in_game->inventory->is_item_selected = FALSE;
    rpg->game->in_game->inventory->selected_item = NO_WEAPON;
}

void drops_weapon(rpg_t *rpg)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue &&
    rpg->game->in_game->inventory->is_item_selected == TRUE) {
        if (rpg->game->in_game->inventory->is_area_filled[WEAPON] == FALSE &&
        ((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 370.5)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 366.5)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 446.5)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 442.5)))
            drop_weapon(rpg, rpg->game->in_game->inventory->selected_item);
        else {
            sfSprite_setPosition(rpg->game->in_game->inventory->weapon
            [rpg->game->in_game->inventory->selected_item],
            rpg->game->in_game->inventory->pos_weapon
            [rpg->game->in_game->inventory->selected_item]);
            rpg->game->in_game->inventory->selected_item = NO_WEAPON;
        }
    }
}

void detect_stuff(rpg_t *rpg)
{
    // sfVector2f mouse = sfRenderWindow_mapPixelToCoords(rpg->basic->wnd->my_wnd,
    // sfMouse_getPositionRenderWindow(rpg->basic->wnd->my_wnd), NULL);

    if (rpg->game->in_game->inventory->is_item_selected == FALSE)
        detect_weapon(rpg);
    if (rpg->game->in_game->inventory->selected_item != NO_WEAPON) {
        drag(rpg, rpg->game->in_game->inventory->selected_item);
        drops_weapon(rpg);
    }
        //calc_vector(rpg, WEAPON, rpg->game->in_game->inventory->selected_item);
    //detect_ammo(rpg);
    //detect_bulletproofvest(rpg);
}

void display_inventory(rpg_t *rpg)
{
    sfVector2f inventory_pos = {461.5, 366.5};
    int charac = rpg->menu->main_menu->new_game->character_chosen;

    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->game->in_game->inventory->inventory, NULL);
    sfSprite_setPosition(rpg->menu->main_menu->new_game->characters[charac],
    inventory_pos);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->menu->main_menu->new_game->characters[charac], NULL);
    move_characters(rpg, charac);
    display_weapons(rpg);
    detect_stuff(rpg);
}