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
    // if (rpg->basics == NULL) exit(84);
    rpg->main_menu = malloc(sizeof(main_menu_t));
    // if (rpg->main_menu == NULL) exit(84);
    return (0);
}

int init_values(rpg_t *rpg)
{
    rpg->basics->clock = sfClock_create();
    rpg->basics->fps = 60;
    rpg->basics->time_total = 0;
    rpg->basics->time_loop = 0;
    rpg->status = 0;
    init_main_menu(rpg);
    return (0);
}

int main(int ac, char **av)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));

    if (rpg == NULL)
        return (84);
    init_structs(rpg);
    //init_values(rpg);
    create_window(rpg);
    return (0);
}