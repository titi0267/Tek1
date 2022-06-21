/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** move_direction
*/

#include "../../../include/func_name.h"

void move_bullet_up(rpg_t *rpg, bullets_t *bullet_list)
{
    int i = 0;

    if (rpg->game->in_game->map->dir == UP)
        bullet_list->bullet_pos.y -= (5 - rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status]);
    if (rpg->game->in_game->map->dir == DOWN)
        bullet_list->bullet_pos.y -= (5 + rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status]);
    if (rpg->game->in_game->map->dir == LEFT)
        bullet_list->bullet_pos = vect_x_y(bullet_list->bullet_pos,
        rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status], -5);
    if (rpg->game->in_game->map->dir == RIGHT)
        bullet_list->bullet_pos = vect_x_y(bullet_list->bullet_pos,
        -rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status], -5);
    i++;
    if (rpg->game->in_game->map->dir == 5)
        bullet_list->bullet_pos.y -= 5;
    bullet_list->finish_line -= 5;
}

void move_bullet_left(rpg_t *rpg, bullets_t *bullet_list)
{
    int i = 0;

    if (rpg->game->in_game->map->dir == UP)
        bullet_list->bullet_pos = vect_x_y(bullet_list->bullet_pos, -5,
        rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status]);
    if (rpg->game->in_game->map->dir == DOWN)
        bullet_list->bullet_pos = vect_x_y(bullet_list->bullet_pos, -5,
        -rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status]);
    if (rpg->game->in_game->map->dir == LEFT)
        bullet_list->bullet_pos.x -= (5 - rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status]);
    if (rpg->game->in_game->map->dir == RIGHT)
        bullet_list->bullet_pos.x -= (5 + rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status]);
    i++;
    if (rpg->game->in_game->map->dir == 5)
        bullet_list->bullet_pos.x -= 5;
    bullet_list->finish_line -= 5;
}

void move_bullet_right(rpg_t *rpg, bullets_t *bullet_list)
{
    int i = 0;

    if (rpg->game->in_game->map->dir == RIGHT) {
        bullet_list->bullet_pos.x += (5 - rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status]);
    }
    if (rpg->game->in_game->map->dir == LEFT) {
        bullet_list->bullet_pos.x += (5 + rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status]);
    }
    if (rpg->game->in_game->map->dir == DOWN) {
        bullet_list->bullet_pos.x += 5;
        bullet_list->bullet_pos.y -= rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status];
    }
    if (rpg->game->in_game->map->dir == UP) {
        bullet_list->bullet_pos.x += 5;
        bullet_list->bullet_pos.y += rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status];
    }
    i++;
    if (rpg->game->in_game->map->dir == 5)
        bullet_list->bullet_pos.x += 5;
    bullet_list->finish_line -= 5;
}

void move_bullet_down(rpg_t *rpg, bullets_t *bullet_list)
{
    int i = 0;

    if (rpg->game->in_game->map->dir == UP) {
        bullet_list->bullet_pos.y += (5 + rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status]);
        bullet_list->finish_line -= 5;
    }
    if (rpg->game->in_game->map->dir == DOWN) {
        bullet_list->bullet_pos.y += (5 - rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status]);
        bullet_list->finish_line -= 5;
    }
    if (rpg->game->in_game->map->dir == LEFT) {
        bullet_list->bullet_pos.y += 5;
        bullet_list->bullet_pos.x += rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status];
        bullet_list->finish_line -= 5;
    }
    if (rpg->game->in_game->map->dir == RIGHT) {
        bullet_list->bullet_pos.y += 5;
        bullet_list->bullet_pos.x -= rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status];
        bullet_list->finish_line -= 5;
    }
    i++;
    if (rpg->game->in_game->map->dir == 5) {
        bullet_list->bullet_pos.y += 5;
        bullet_list->finish_line -= 5;
    }
}