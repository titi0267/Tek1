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

void display_weapons(rpg_t *rpg)
{
    sfVector2f *pos_wp = malloc(sizeof(sfVector2f) * 5);
    pos_wp[SMG] = put_in_vector2f(825.5, 421.5);
    pos_wp[KNIFE] = put_in_vector2f(916.5, 421.5);
    pos_wp[GUN] = put_in_vector2f(1007.5, 421.5);
    pos_wp[TAZER] = put_in_vector2f(1098.5, 421.5);
    for (int i = SMG; i < NO_WEAPON; i++) {
        rpg->game->in_game->inventory->pos_weapon[i] = pos_wp[i];
        sfSprite_setPosition(rpg->game->in_game->inventory->weapon[i],
        pos_wp[i]);
    }
}

void detect_weapon(rpg_t *rpg)
{
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 396)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 362)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 645)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 709))) {
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->menu->main_menu->new_game->select[MAXOU], NULL);
        move_characters(rpg, MAXOU);
    }
}

void detect_stuff(rpg_t *rpg)
{
    detect_weapon(rpg);
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
    // display_weapons(rpg);
    detect_stuff(rpg);
}