/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** cinematics
*/

#include "../../../include/func_name.h"

void print_life(rpg_t *rpg)
{
    if (!on_cine(rpg)) {
        if (rpg->game->in_game->stats->player_stats[P_LIFE]->value < 0)
            rpg->game->in_game->stats->player_stats[P_LIFE]->value = 0;
        rpg->game->in_game->stats->life_size.x =
        (rpg->game->in_game->stats->player_stats[P_LIFE]->value * 400) / 100;
        sfRectangleShape_setSize(rpg->game->in_game->stats->life,
        rpg->game->in_game->stats->life_size);
        sfRenderWindow_drawRectangleShape(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->stats->life, NULL);
        sfRenderWindow_drawRectangleShape(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->stats->life_border, NULL);
    }
}

void print_xp(rpg_t *rpg)
{
    if (!on_cine(rpg)) {
        if (rpg->game->in_game->stats->xp_value >=
        rpg->game->in_game->stats->xp_max_value) {
            rpg->game->in_game->stats->xp_value =
            rpg->game->in_game->stats->xp_value -
            rpg->game->in_game->stats->xp_max_value;
            rpg->game->in_game->stats->player_stats[P_LIFE]->value = 100;
            rpg->game->in_game->stats->level_up = 1;
            rpg->game->in_game->stats->level++;
            rpg->game->in_game->stats->xp_max_value += 40;
        }
        rpg->game->in_game->stats->xp_size.x =
        (rpg->game->in_game->stats->xp_value * 300) /
        rpg->game->in_game->stats->xp_max_value;
        sfRectangleShape_setSize(rpg->game->in_game->stats->xp,
        rpg->game->in_game->stats->xp_size);
        sfRenderWindow_drawRectangleShape(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->stats->xp, NULL);
        sfRenderWindow_drawRectangleShape(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->stats->xp_border, NULL);
    }
}

void hitbox_level_up(rpg_t *rpg)
{
    static float nbr = 0;

    nbr += rpg->basic->cnf->clk->time_loop;
    if ((rpg->basic->evt->event.type == sfEvtMouseButtonPressed) &&
    ((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1527.1)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 558.5)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1562.1)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 593.5)) && nbr >= 0.2) {
        rpg->game->in_game->stats->level--;
        rpg->game->in_game->stats->player_stats[P_DAMAGE]->base_value += 5;
        nbr = 0;
    }
    else if ((rpg->basic->evt->event.type == sfEvtMouseButtonPressed) &&
    ((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1527.1)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 665)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1562.1)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 690)) && nbr >= 0.2) {
        rpg->game->in_game->stats->level--;
        rpg->game->in_game->stats->player_stats[P_ARMOR]->base_value += 2;
        nbr = 0;
    }
}

void print_level_up(rpg_t *rpg)
{
    if (rpg->game->in_game->stats->level > 0) {
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->inventory->add_damage, NULL);
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->inventory->add_armor, NULL);
        sfText_setString(rpg->game->in_game->inventory->level_up_text, my_strcat
        ("Vous avez ", my_strcat(my_putnbr(rpg->game->in_game->stats->level),
        " competences a ameliorer")));
        sfRenderWindow_drawText(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->inventory->level_up_text, NULL);
        hitbox_level_up(rpg);
    }
}

void print_xp_life(rpg_t *rpg)
{
    print_xp(rpg);
    print_life(rpg);
    creat_level_up(rpg);
}
