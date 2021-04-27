/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** close
*/

#include "../include/func_name.h"

void destroy_basic(rpg_t *rpg)
{
    sfClock_destroy(rpg->basic->cnf->clk->clock);
    sfSoundBuffer_destroy(rpg->menu->intro->intro_snd->create_start);
    sfSoundBuffer_destroy(rpg->menu->main_menu->menu_snd->create_a_menu);
    sfSoundBuffer_destroy(rpg->game->start->cine1);
    sfSound_destroy(rpg->menu->intro->intro_snd->start);
    sfSound_destroy(rpg->menu->main_menu->menu_snd->a_menu);
    sfSound_destroy(rpg->game->start->cinematic_1);
    sfRenderWindow_destroy(rpg->basic->wnd->my_wnd);
}

void destroy_menu(rpg_t *rpg)
{
    for (int i = NEW_GAME; i < NONE; i++)
        sfSprite_destroy(rpg->menu->main_menu->menu_spt->menu[i]);
    sfSprite_destroy(rpg->menu->intro->intro_basil->basil_spt);
    sfSprite_destroy(rpg->menu->main_menu->menu_spt->main_menu);
    sfSprite_destroy(rpg->menu->bgd_adn->background);
    sfSprite_destroy(rpg->menu->main_menu->new_game->background);
    for (int i = MAXOU; i < NO_CHARACTERS; i++)
        sfSprite_destroy(rpg->menu->main_menu->new_game->select[i]);
    for (int i = CIRCLE_MUSIC; i < FPS60; i++)
        sfSprite_destroy(rpg->menu->stg->graph->graph_btn->graphismes[i]);
    for (int i = GRAPH_F; i < NO; i++)
        sfSprite_destroy(rpg->menu->stg->opt[i]);
    sfSprite_destroy(rpg->menu->intro->intro_pegi->pegi_spt);
    for (int i = 0; i <= QUADCOPTER; i++)
        sfText_destroy(rpg->menu->stg->key_bnd->control[i]->box);
}

void destroy_game(rpg_t *rpg)
{
    sfSprite_destroy(rpg->game->start->radio);
    for (int i = GRAPH; i < NO; i++)
        sfSprite_destroy(rpg->menu->stg->opt_exit[i]);
    for (int i = RESUME_PAUSE; i < NO_BUTTON_PAUSE; i++)
        sfSprite_destroy(rpg->game->in_game->ig_menus->pause_menu[i]);
    for (int i = SMG; i < NO_WEAPON; i++)
        sfSprite_destroy(rpg->game->in_game->inventory->weapon[i]);
    for (int i = TUTO1; i <= TUTO5; i++)
        sfSprite_destroy(rpg->tutorial->instruct[i]);
    for (int i = MAP_INSIDE_POLICE; i != NO_MAP; i++) {
        sfSprite_destroy(rpg->game->in_game->map->maps[i]);
        sfImage_destroy(rpg->game->in_game->map->collisions[i]);
    }

}

void destroy_all(rpg_t *rpg)
{
    destroy_game(rpg);
    destroy_menu(rpg);
    destroy_basic(rpg);
}