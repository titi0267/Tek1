/*
** EPITECH PROJECT, 2021
** malloc structs
** File description:
** basic.h malloc
*/

#include "../../include/rpg.h"

int basic_malloc(basic_t *basic)
{
    if ((basic->cnf = malloc(sizeof(config_t)) == NULL)
        return (MALLOC_ERROR);
    if ((basic->cnf->clk = malloc(sizeof(cloc_t)) == NULL)
        return (MALLOC_ERROR);
    if (basic->cnf->scr_cnf = malloc(sizeof(screen_conf_t)) == NULL)
        return (MALLOC_ERROR);
    if (basic->wnd = malloc(sizeof(window_t)) == NULL)
        return (MALLOC_ERROR);
    if (basic->evt = malloc(sizeof(event_t)) == NULL)
        return (MALLOC_ERROR);
    return (0);
}