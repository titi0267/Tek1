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
    sfRenderWindow_setMouseCursorVisible(rpg->basic->wnd->my_wnd, sfFalse);
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

void drop_weapon(rpg_t *rpg)
{
    sfRenderWindow_setMouseCursorVisible(rpg->basic->wnd->my_wnd, sfTrue);
    /*sfSprite_setPosition(rpg->game->in_game->inventory->weapon[weapon],
    rpg->game->in_game->inventory->pos_storage[WEAPON]);*/
    rpg->game->in_game->inventory->release_weapon = TRUE;
    rpg->game->in_game->inventory->selected_item = NO_WEAPON;
}

void drop_pos_weapon(rpg_t *rpg)
{
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 370)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 370)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 450)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 450)) &&
    rpg->game->in_game->inventory->is_area_filled[WEAPON] == NO_WEAPON) {
        rpg->game->in_game->inventory->is_area_filled[WEAPON] =
        rpg->game->in_game->inventory->selected_item;
        sfSprite_setPosition(rpg->game->in_game->inventory->weapon
        [rpg->game->in_game->inventory->selected_item],
        rpg->game->in_game->inventory->pos_storage[WEAPON]);
    }
    for (int i = 0; i <= 24; i++) {
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg,
        rpg->game->in_game->inventory->box_pos[i][0].x)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg,
        rpg->game->in_game->inventory->box_pos[i][0].y)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg,
        rpg->game->in_game->inventory->box_pos[i][1].x)) &&
        (rpg->basic->cnf->mouse.y <= adapt_y(rpg,
        rpg->game->in_game->inventory->box_pos[i][1].y))) {
            //printf("i = %i\n", i);
            rpg->game->in_game->inventory->pos_weapon
            [rpg->game->in_game->inventory->selected_item] = put_in_vector2f(
            (float)rpg->game->in_game->inventory->box_pos[i][0].x,
            (float)rpg->game->in_game->inventory->box_pos[i][0].y);
        }
    }
    drop_weapon(rpg);
    rpg->game->in_game->inventory->on_click = FALSE;
    rpg->game->in_game->inventory->click_weapon = FALSE;
}

void drop3(rpg_t *rpg)
{
    static float nbr = 0;
    static float nbr1 = 1.1;

    if (rpg->basic->evt->event.type == sfEvtMouseButtonPressed &&
    rpg->game->in_game->inventory->click_weapon == FALSE &&
    rpg->game->in_game->inventory->release_weapon == FALSE) {
        detect_weapon(rpg);
        //printf("Which weapon = %i\n", rpg->game->in_game->inventory->selected_item);
    }
    if (rpg->game->in_game->inventory->click_weapon == TRUE) {
        nbr += rpg->basic->cnf->clk->time_loop;
        if (rpg->basic->evt->event.type == sfEvtMouseButtonReleased) {
            nbr = 0;
            rpg->game->in_game->inventory->on_click = TRUE;
        }
        drag(rpg, rpg->game->in_game->inventory->selected_item);
    }
    if (rpg->game->in_game->inventory->on_click == TRUE) {
        //printf("clicked = %i & nbr = %f\n", rpg->game->in_game->inventory->on_click, nbr);
        if (rpg->basic->evt->event.type == sfEvtMouseButtonPressed && nbr > 1) {
            //printf("mouse.x = %i & mouse.y = %i\n", rpg->basic->cnf->mouse.x, rpg->basic->cnf->mouse.y);
            drop_pos_weapon(rpg);
        }
    }
    if (rpg->game->in_game->inventory->release_weapon == TRUE) {
        nbr1 += rpg->basic->cnf->clk->time_loop;
        if (nbr1 > 1) {
            rpg->game->in_game->inventory->release_weapon = FALSE;
            nbr1 = 0;
        }
    }
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
    drop3(rpg);
}