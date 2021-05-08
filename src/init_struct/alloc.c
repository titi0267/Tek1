/*
** EPITECH PROJECT, 2021
** malloc structs
** File description:
** basic.h malloc
*/

#include "../../include/func_name.h"

int basic_malloc(basic_t *basic)
{
    int i = 0;

    if ((basic->cnf = malloc(sizeof(config_t))) == NULL)
        return (MALLOC_ERROR);
    if ((basic->cnf->clk = malloc(sizeof(cloc_t))) == NULL)
        return (MALLOC_ERROR);
    if ((basic->cnf->scr_cnf = malloc(sizeof(screen_conf_t))) == NULL)
        return (MALLOC_ERROR);
    i++;
    if ((basic->wnd = malloc(sizeof(window_t))) == NULL)
        return (MALLOC_ERROR);
    if ((basic->evt = malloc(sizeof(event_t))) == NULL)
        return (MALLOC_ERROR);
    return (0);
}

static int intro_malloc(intro_t *intro)
{
    if ((intro->intro_basil = malloc(sizeof(intro_basil_t))) == NULL)
        return (MALLOC_ERROR);
    if ((intro->intro_snd = malloc(sizeof(intro_sound_t))) == NULL)
        return (MALLOC_ERROR);
    if ((intro->intro_pegi = malloc(sizeof(intro_pegi_t))) == NULL)
        return (MALLOC_ERROR);
    return (0);
}

int menu_alloc(menu_t *menu)
{
    int i = 0;

    if ((menu->intro = malloc(sizeof(intro_t))) == NULL)
        return (MALLOC_ERROR);
    if (intro_malloc(menu->intro) == MALLOC_ERROR)
        return (MALLOC_ERROR);
    if ((menu->main_menu = malloc(sizeof(main_menu_t))) == NULL)
        return (MALLOC_ERROR);
    if ((menu->bgd_adn = malloc(sizeof(background_adn_t))) == NULL)
        return (MALLOC_ERROR);
    i++;
    if ((menu->main_menu->menu_snd = malloc(sizeof(menu_snd_t))) == NULL)
        return (MALLOC_ERROR);
    if ((menu->main_menu->menu_spt = malloc(sizeof(menu_spt_t))) == NULL)
        return (MALLOC_ERROR);
    if ((menu->stg = malloc(sizeof(setting_t))) == NULL)
        return (MALLOC_ERROR);
    if ((menu->stg->stg_snd = malloc(sizeof(stg_sound_t))) == NULL)
        return (MALLOC_ERROR);
    return (0);
}

static int menu_alloc_next2(menu_t *menu)
{
    int i = 0;

    if ((menu->stg->graph->graph_bgd =
    malloc(sizeof(bgd_graph_stg_t))) == NULL)
        return (MALLOC_ERROR);
    if ((menu->stg->key_bnd = malloc(sizeof(key_bind_t))) == NULL)
        return (MALLOC_ERROR);
    if (malloc_text(menu) == MALLOC_ERROR)
        return (MALLOC_ERROR);
    if ((menu->stg->key_bnd->control_bgd = malloc(sizeof(bgd_control_stg_t)))
        == NULL)
        return (MALLOC_ERROR);
    i++;
    if ((menu->main_menu->new_game = malloc(sizeof(new_game_t))) == NULL)
        return (MALLOC_ERROR);
    return (0);
}

int menu_alloc_next(menu_t *menu)
{
    if ((menu->stg->stg_snd->bgd_stg =
    malloc(sizeof(bgd_sound_stg_t))) == NULL)
        return (MALLOC_ERROR);
    if ((menu->stg->stg_snd->snd_btn =
    malloc(sizeof(stg_sound_btn_t))) == NULL)
        return (MALLOC_ERROR);
    if ((menu->stg->graph = malloc(sizeof(graph_t))) == NULL)
        return (MALLOC_ERROR);
    if ((menu->stg->graph->graph_btn = malloc(sizeof(graph_btn_t))) == NULL)
        return (MALLOC_ERROR);
    return (menu_alloc_next2(menu));
}