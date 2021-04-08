/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** rpg
*/

#include "../include/rpg.h"

int init_structs(rpg_t *rpg)
{
    rpg->basics = malloc(sizeof(basics_t));
    if (rpg->basics == NULL) exit(84);
    rpg->main_menu = malloc(sizeof(main_menu_t));
    if (rpg->main_menu == NULL) exit(84);
    rpg->control = malloc(sizeof(control_t));
    if (rpg->control == NULL) exit(84);
    return (0);
}

int init_values(rpg_t *rpg)
{
    rpg->basics->clock = sfClock_create();
    rpg->basics->fps = 60;
    rpg->basics->time_total = 0;
    rpg->basics->time_loop = 0;
    rpg->main_menu->opt_status = 0;
    rpg->status = 0;
    rpg->basics->resolution = 0;
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
    init_structs(rpg);
    init_values(rpg);
    init_function(rpg);
    create_window(rpg);
    return (0);
}