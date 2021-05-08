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
        if (rpg->game->in_game->stats->xp_value >= 100) {
            rpg->game->in_game->stats->xp_value =
            rpg->game->in_game->stats->xp_value - 100;
            rpg->game->in_game->stats->player_stats[P_LIFE]->value = 100;
            rpg->game->in_game->stats->level_up = 1;
            rpg->game->in_game->stats->level++;
        }
        rpg->game->in_game->stats->xp_size.x =
        (rpg->game->in_game->stats->xp_value * 300) / 100;
        sfRectangleShape_setSize(rpg->game->in_game->stats->xp,
        rpg->game->in_game->stats->xp_size);
        sfRenderWindow_drawRectangleShape(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->stats->xp, NULL);
        sfRenderWindow_drawRectangleShape(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->stats->xp_border, NULL);
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
        " competences à améliorer")));
        sfRenderWindow_drawText(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->inventory->level_up_text, NULL);
    }
}

void print_xp_life(rpg_t *rpg)
{
    print_xp(rpg);
    print_life(rpg);
    creat_level_up(rpg);
}
