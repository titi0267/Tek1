/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** free_all
*/

#include "../include/func_name.h"

void free_game(rpg_t *rpg)
{
    free(rpg->game->in_game->ig_sound);
    free(rpg->game->in_game->inventory);
    free(rpg->game->in_game->ig_menus);
    free(rpg->game->in_game->objects);
    free(rpg->game->in_game->nmi_list);
    free(rpg->game->in_game->nmi);
    free(rpg->game->in_game->map->pos_map);
    free(rpg->game->in_game->map);
    free(rpg->game->in_game->phone);
    free(rpg->game->in_game);
    free(rpg->game->end);
    free(rpg->game->start);
}

void free_intro(rpg_t *rpg)
{
    free(rpg->menu->intro->intro_basil);
    free(rpg->menu->intro->intro_snd);
    free(rpg->menu->intro->intro_pegi);
    free(rpg->menu->intro);
}

void free_intro_menu(rpg_t *rpg)
{
    free(rpg->basic->cnf->clk);
    free(rpg->basic->cnf->scr_cnf);
    free(rpg->basic->cnf);
    free(rpg->basic->wnd);
    free(rpg->basic->evt);
    free(rpg->menu->bgd_adn);
    free(rpg->menu->main_menu->menu_snd);
    free(rpg->menu->main_menu->menu_spt);
    free(rpg->menu->main_menu->new_game);
    free(rpg->menu->main_menu);
    free(rpg->menu->stg->key_bnd->control_bgd);
    free(rpg->menu->stg->key_bnd);
    free(rpg->menu->stg->stg_snd->bgd_stg);
    free(rpg->menu->stg->stg_snd->snd_btn);
    free(rpg->menu->stg->stg_snd);
    free(rpg->menu->stg->graph->graph_bgd);
    free(rpg->menu->stg->graph->graph_btn);
    free(rpg->menu->stg->graph);
    free(rpg->menu->stg);
}

void free_all(rpg_t *rpg)
{
    free_game(rpg);
    free_intro(rpg);
    free_intro_menu(rpg);
    free(rpg->basic);
    free(rpg->menu);
    free(rpg->game);
    free(rpg->tutorial);
}