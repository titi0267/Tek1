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

int intro_malloc(intro_t *intro)
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
    if ((menu->intro = malloc(sizeof(intro_t))) == NULL)
        return (MALLOC_ERROR);
    if (intro_malloc(menu->intro) == MALLOC_ERROR)
        return (MALLOC_ERROR);
    if ((menu->menu_snd = malloc(sizeof(menu_snd_t))) == NULL)
        return (MALLOC_ERROR);
    if ((menu->bgd_adn = malloc(sizeof(background_adn_t))) == NULL)
        return (MALLOC_ERROR);
    return (0);
}