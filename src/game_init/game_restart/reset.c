/*
** EPITECH PROJECT, 2021
** reset by Timothy CONIEL
** File description:
** reset.c
*/
#include "../../../include/my.h"

void init_button(menu_t *menu)
{
    menu->position.x = 500;
    menu->position.y = 400;
    menu->pos_black.x = 500;
    menu->pos_black.y = 400;
    sfSprite_setPosition(menu->button, menu->position);
    menu->scale.x = 5;
    menu->scale.y = 5;
    menu->black_scale.x = 4;
    menu->black_scale.y = 4;
    menu->button_black = 0;
}

int init_enemy(enemy_t *enemy, map_t *buff, player_t *bird)
{
    buff->char_val = 0;
    buff->lin_val = 0;
    for (; buff->lin_val != 11; buff->lin_val++) {
        for (; buff->line[buff->lin_val][buff->char_val] != '\0';
            buff->char_val++) {
            space_btw_pipe(enemy, buff);
            if (buff->line[buff->lin_val][buff->char_val] ==
                ' ' && (buff->char_val % 8) == 0)
                fill_array(enemy, bird);
            place_obstacles(enemy, buff);
            place_obstacles_next(enemy, buff);
        }
        buff->char_val = 0;
    }
    return (0);
}

void reset_static(enemy_t *enemy, player_t *bird)
{
    enemy->pos_di = 0;
    enemy->pos_x = 0;
    enemy->pos_uf = 0;
    bird->col_arr = 1;
    enemy->death_i = 0;
    bird->move_pipe = 1;
    enemy->fill_d = 0;
    bird->aft_pip = 1;
    for (int h = 0; h < 18; h++)
        bird->collision[h].x = 0;
    bird->angle = 0;
    bird->rotate_speed = 1;
}

void restart(gather_t *gather, map_t *buff)
{
    if (gather->menu.black_scale.x >= 5 || gather->menu.black_scale.y >= 5)
        gather->menu.restart = 1;
    if (gather->menu.restart == 1)
        re_init(gather, buff);
}