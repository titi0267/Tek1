/*
** EPITECH PROJECT, 2021
** init_car
** File description:
** init_car
*/

#include "../../../include/func_name.h"

void print_car(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->game->in_game->objects->car->car,
    rpg->game->in_game->objects->car->car_pos);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->game->in_game->objects->car->car, NULL);
}

void init_rect_car(objects_t *obj)
{
    obj->car->rect_car.height = 365.7;
    obj->car->rect_car.width = 365.7;
    obj->car->rect_car.left = 0;
    obj->car->rect_car.top = 0;
    sfSprite_setTextureRect(obj->car->car, obj->car->rect_car);
}

void init_car_spt(rpg_t *rpg)
{
    sfTexture *car_tex = sfTexture_createFromFile
    ("assets/perso/policecar.png", NULL);

    rpg->game->in_game->objects->car->car = sfSprite_create();
    sfSprite_setTexture(rpg->game->in_game->objects->car->car,
    car_tex, sfTrue);
    init_rect_car(rpg->game->in_game->objects);
}