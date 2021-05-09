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
        rpg->game->in_game->objects->car->car_pos_tuto.x = 490.0;
        rpg->game->in_game->objects->car->car_pos_tuto.y = 300.0;
        rpg->game->in_game->objects->car->car_pos.x = 1200;
        rpg->game->in_game->objects->car->car_pos.y = 170;
        rpg->game->in_game->map->draw_car = FALSE;
        if (rpg->game->in_game->map->status != MAP_TUTO) {
            rpg->game->in_game->objects->car->last_dir = 1;
            rpg->game->in_game->objects->car->top_car = 494;
        }
        rpg->game->in_game->objects->car->status = 0;
    }
}

void move_rect_car_next(rpg_t *rpg, int direction)
{
    static float time_car = 0;

    time_car += rpg->basic->cnf->clk->time_loop;
    if (time_car >= 0.2 &&
    rpg->game->in_game->objects->car->car_line <= 1) {
        time_car = 0;
        if (direction == 0)
            rpg->game->in_game->objects->car->rect_car[direction].left =
            (rpg->game->in_game->objects->car->car_line == 1) ? 496 : 131;
        else
            rpg->game->in_game->objects->car->rect_car[direction].left =
            (rpg->game->in_game->objects->car->car_line == 1) ? 446 : 81;
        rpg->game->in_game->objects->car->car_line++;
        }
    rpg->game->in_game->objects->car->car_line =
    (rpg->game->in_game->objects->car->car_line > 1) ? 0 :
    rpg->game->in_game->objects->car->car_line;
}

void print_car(rpg_t *rpg, int direction)
{
    if (rpg->game->in_game->objects->speed_status == CAR_SPEED) {
        move_rect_car_next(rpg, direction);
    } else {
        direction = rpg->game->in_game->objects->car->last_dir;
    }
    sfSprite_setTextureRect(rpg->game->in_game->objects->car->car,
    rpg->game->in_game->objects->car->rect_car[direction]);
    if (rpg->game->in_game->map->status == MAP_TUTO)
        sfSprite_setPosition(rpg->game->in_game->objects->car->car,
        rpg->game->in_game->objects->car->car_pos_tuto);
    else
        sfSprite_setPosition(rpg->game->in_game->objects->car->car,
        rpg->game->in_game->objects->car->car_pos);
    if (rpg->game->in_game->map->draw_car == TRUE
    || rpg->game->in_game->map->status == rpg->game->in_game->map->car_map)
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->objects->car->car, NULL);
}

void rect_move_car(rpg_t *rpg, objects_t *obj, int direction)
{
    if (direction == LEFT && obj->speed_status == CAR_SPEED) {
        obj->car->last_dir = 1;
        obj->car->top_car = 494;
    }
    if (direction == RIGHT && obj->speed_status == CAR_SPEED) {
        obj->car->last_dir = 1;
        obj->car->top_car = 1224;
    }
    if (direction == UP && obj->speed_status == CAR_SPEED) {
        obj->car->last_dir = 0;
        obj->car->top_car = 119;
    }
    if (direction == DOWN && obj->speed_status == CAR_SPEED) {
        obj->car->last_dir = 0;
        obj->car->top_car = 846;
    }
    obj->car->rect_car[obj->car->last_dir].top =
    obj->car->top_car;
    print_car(rpg, obj->car->last_dir);
}

void init_rect_car(objects_t *obj)
{
    obj->car->rect_car = malloc(sizeof(sfIntRect) * 2);
    obj->car->rect_car[0].height = 128;
    obj->car->rect_car[0].width = 103;
    obj->car->rect_car[0].left = 131;
    obj->car->rect_car[0].top = 119;
    obj->car->rect_car[1].height = 109;
    obj->car->rect_car[1].width = 203;
    obj->car->rect_car[1].left = 81;
    obj->car->rect_car[1].top = 494;
    obj->car->car_line = 0;
    obj->car->status = -1;
    obj->car->last_dir = 0;
    obj->car->top_car = 119;
    sfSprite_setTextureRect(obj->car->car, obj->car->rect_car[1]);
    sfSprite_setTextureRect(obj->car->car, obj->car->rect_car[0]);
}