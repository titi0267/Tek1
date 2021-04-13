/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** rpg
*/

#include "../include/func_name.h"

int init_basic_value(basic_t *basic)
{
    basic->cnf->clk->clock = sfClock_create();
    basic->cnf->scr_cnf->fps = 60;
    basic->cnf->clk->time_total = 0;
    basic->cnf->clk->time_loop = 0;
    //rpg->main_menu->opt_status = 0;
    //rpg->status = 0;
    basic->cnf->scr_cnf->resolution = 0;
    return (0);
}

void init_function(rpg_t *rpg)
{
    init_controls(rpg);
    init_rect_adn(rpg);
    init_main_menu(rpg);
    init_logo_spt(rpg);
    init_pegi_spt(rpg);
    create_boom(rpg);
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
    init_basic_value(rpg->basic);
    init_function(rpg);
    open_window(rpg);
    return (0);
}