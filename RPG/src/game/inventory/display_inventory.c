/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** display_inventory
*/

#include "../../../include/func_name.h"

void drop_box_invetory(rpg_t *rpg)
{
    drop_all_boxes(rpg);
    sfRenderWindow_setMouseCursorVisible(rpg->basic->wnd->my_wnd, sfTrue);
    rpg->game->in_game->inventory->release_weapon = TRUE;
    rpg->game->in_game->inventory->selected_item = NO_WEAPON;
    rpg->game->in_game->inventory->on_click = FALSE;
    rpg->game->in_game->inventory->click_weapon = FALSE;
}

void drag_and_drop_main_next(rpg_t *rpg)
{
    static float nbr = 0;

    if (rpg->basic->evt->event.type == sfEvtMouseButtonPressed &&
    rpg->game->in_game->inventory->click_weapon == FALSE &&
    rpg->game->in_game->inventory->release_weapon == FALSE) {
        detect_inventory_object(rpg);
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
        if (rpg->basic->evt->event.type == sfEvtMouseButtonPressed && nbr > 0.1)
            drop_box_invetory(rpg);
    }
}

void drag_and_drop_main(rpg_t *rpg)
{
    static float nbr1 = 0;

    drag_and_drop_main_next(rpg);
    if (rpg->game->in_game->inventory->release_weapon == TRUE) {
        nbr1 += rpg->basic->cnf->clk->time_loop;
        if (nbr1 > 0.1) {
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
    display_loots(rpg);
    print_stats(rpg);
    print_level_up(rpg);
    drag_and_drop_main(rpg);
}