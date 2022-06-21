/*
** EPITECH PROJECT, 2021
** lose
** File description:
** lose
*/

#include "../../../include/func_name.h"

void init_lose_text(rpg_t *rpg)
{
    rpg->game->in_game->stats->lose_txt = sfText_create();
    sfText_setString(rpg->game->in_game->stats->lose_txt
    , "Tu as perdu essaye encore");
    sfText_setFont(rpg->game->in_game->stats->lose_txt,
    sfFont_createFromFile("assets/fonts/aqua.ttf"));
    sfText_setCharacterSize(rpg->game->in_game->stats->lose_txt, 50);
    sfText_setPosition(rpg->game->in_game->stats->lose_txt,
    put_in_vector2f(680, 330));
    sfText_setColor(rpg->game->in_game->stats->lose_txt, sfRed);
    rpg->game->in_game->stats->losing = 0;
}

void lose_game(rpg_t *rpg)
{
    static float time = 0;

    if (rpg->game->in_game->stats->player_stats[P_LIFE]->value <= 0) {
        destroy_enemies(rpg);
        rpg->game->in_game->stats->losing = 1;
        reload_new_game(rpg);
        rpg->menu->status = ON_GAME;
        rpg->game->in_game->game_status = GM_BEGIN;
    }
    if (rpg->game->in_game->stats->losing == 1) {
        time += rpg->basic->cnf->clk->time_loop;
        sfRenderWindow_drawText(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->stats->lose_txt, NULL);
        if (time >= 5) {
            time = 0;
            rpg->game->in_game->stats->losing = 0;
        }
    }
}