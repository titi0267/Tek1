/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** rpg
*/

#include "../include/func_name.h"

int init_basic_value(rpg_t *rpg)
{
    rpg->basic->cnf->clk->clock = sfClock_create();
    rpg->basic->cnf->scr_cnf->fps = 60;
    rpg->basic->cnf->clk->time_total = 0;
    rpg->basic->cnf->clk->time_loop = 0;
    rpg->menu->stg->stg_scene = GRAPH_SCN;
    rpg->menu->status = ON_BASIL;
    rpg->basic->cnf->scr_cnf->resolution = 0;
    rpg->menu->stg->stg_snd->status == -1;
    return (0);
}

void init_function(rpg_t *rpg)
{
    init_controls(rpg);
    init_rect_adn(rpg);
    init_main_menu(rpg);
    init_logo_spt(rpg);
    init_pegi_spt(rpg);
    create_boom(rpg->menu);
    init_option1(rpg);
    create_size_square(rpg);
    sound_cirle(rpg);
    init_bt_opt(rpg);
}

int main(int ac, char **av)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));

    if (rpg == NULL)
        return (84);
    alloc_all(rpg);
    init_basic_value(rpg);
    init_function(rpg);
    open_window(rpg);
    return (0);
}