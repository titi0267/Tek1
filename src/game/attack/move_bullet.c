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
        bullet_list->bullet_pos.y -= 3;
    if (rpg->game->in_game->map->dir == DOWN)
        bullet_list->bullet_pos.y -= 7;
    if (rpg->game->in_game->map->dir == LEFT) {
        bullet_list->bullet_pos.y -= 5;
        bullet_list->bullet_pos.x += rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status];
    }
    if (rpg->game->in_game->map->dir == RIGHT) {
        bullet_list->bullet_pos.y -= 5;
        bullet_list->bullet_pos.x -= rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status];
    }
    i++;
    if (rpg->game->in_game->map->dir == 5) {
        bullet_list->bullet_pos.y -= 5;
    }
}

void move_bullet_left(rpg_t *rpg, bullets_t *bullet_list)
{
    int i = 0;

    if (rpg->game->in_game->map->dir == UP) {
        bullet_list->bullet_pos.x -= 5;
        bullet_list->bullet_pos.y += rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status];
    }
    if (rpg->game->in_game->map->dir == DOWN) {
        bullet_list->bullet_pos.x -= 5;
        bullet_list->bullet_pos.y -= rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status];
    }
    if (rpg->game->in_game->map->dir == LEFT)
        bullet_list->bullet_pos.x -= 3;
    if (rpg->game->in_game->map->dir == RIGHT)
        bullet_list->bullet_pos.x -= 7;
    i++;
    if (rpg->game->in_game->map->dir == 5) {
        bullet_list->bullet_pos.x -= 5;
    }
}

void move_bullet_right(rpg_t *rpg, bullets_t *bullet_list)
{
    int i = 0;

    if (rpg->game->in_game->map->dir == RIGHT)
        bullet_list->bullet_pos.x += 3;
    if (rpg->game->in_game->map->dir == LEFT)
        bullet_list->bullet_pos.x += 7;
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
    if (rpg->game->in_game->map->dir == 5) {
        bullet_list->bullet_pos.x += 5;
    }
}

void move_bullet_down(rpg_t *rpg, bullets_t *bullet_list)
{
    int i = 0;

    if (rpg->game->in_game->map->dir == UP)
        bullet_list->bullet_pos.y += 3;
    if (rpg->game->in_game->map->dir == DOWN)
        bullet_list->bullet_pos.y += 7;
    if (rpg->game->in_game->map->dir == LEFT) {
        bullet_list->bullet_pos.y += 5;
        bullet_list->bullet_pos.x += rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status];
    }
    if (rpg->game->in_game->map->dir == RIGHT) {
        bullet_list->bullet_pos.y += 5;
        bullet_list->bullet_pos.x -= rpg->game->in_game->map->speed
        [rpg->game->in_game->objects->speed_status];
    }
    i++;
    if (rpg->game->in_game->map->dir == 5) {
        bullet_list->bullet_pos.y += 5;
    }
}