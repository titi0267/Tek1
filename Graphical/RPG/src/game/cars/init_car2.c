/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** init_car2
*/

#include "../../../include/func_name.h"

void init_car_spt(rpg_t *rpg)
{
    sfTexture *car_tex = sfTexture_createFromFile
    ("assets/perso/policecar.png", NULL);

    rpg->game->in_game->objects->car->car = sfSprite_create();
    sfSprite_setTexture(rpg->game->in_game->objects->car->car,
    car_tex, sfTrue);
    init_rect_car(rpg->game->in_game->objects);
}