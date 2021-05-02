/*
** EPITECH PROJECT, 2021
** init_car
** File description:
** init_car
*/

#include "../../../include/func_name.h"

void set_pos_car(rpg_t *rpg)
{
    if (rpg->game->in_game->objects->car->status != 0) {
        rpg->game->in_game->objects->car->car_pos.x = 490.0;
        rpg->game->in_game->objects->car->car_pos.y = 300.0;
        rpg->game->in_game->objects->car->status = 0;
    }
}

void print_car(rpg_t *rpg)
{
    if (rpg->basic->cnf->clk->time_car >= 0.2 &&
    rpg->game->in_game->objects->car->car_line <= 1) {
        rpg->basic->cnf->clk->time_car = 0;
        rpg->game->in_game->objects->car->rect_car.left =
        (rpg->game->in_game->objects->car->car_line == 1) ? 495 : 130.7;
        rpg->game->in_game->objects->car->car_line++;
    }
    rpg->game->in_game->objects->car->car_line =
    (rpg->game->in_game->objects->car->car_line > 1) ? 0 :
    rpg->game->in_game->objects->car->car_line;
    sfSprite_setTextureRect(rpg->game->in_game->objects->car->car,
    rpg->game->in_game->objects->car->rect_car);
    sfSprite_setPosition(rpg->game->in_game->objects->car->car,
    rpg->game->in_game->objects->car->car_pos);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->game->in_game->objects->car->car, NULL);
}

void init_rect_car(objects_t *obj)
{
    obj->car->rect_car.height = 128;
    obj->car->rect_car.width = 103;
    obj->car->rect_car.left = 130.7;
    obj->car->rect_car.top = 118;
    obj->car->car_line = 0;
    obj->car->status = -1;
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