/*
** EPITECH PROJECT, 2021
** init obstacles by Timothy CONIEL
** File description:
** init_obstacle.c
*/
#include "../include/my.h"

int malloc_array(enemy_t *enemy, map_t *buff, player_t *bird)
{
    buff->char_val = 0;
    buff->lin_val = 0;
    enemy->pos = malloc(sizeof(sfVector2f) * 89);
    if (enemy->pos == NULL)
        return (-1);
    enemy->pos_d = malloc(sizeof(sfVector2f) * 17);
    if (enemy->pos_d == NULL)
        return (-1);
    enemy->pos_u = malloc(sizeof(sfVector2f) * 17);
    if (enemy->pos_u == NULL)
        return (-1);
    bird->collision = malloc(sizeof(sfVector2f) * 18);
    if (bird->collision == NULL)
        return (-1);
    for (int h = 0; h < 18; h++)
        bird->collision[h].x = 0;
    return (0);
}

void fill_array(enemy_t *enemy, player_t *bird)
{
    static int d = 0;
    int h = 0;

    while (d >= h) {
        if (enemy->enemy_pos.x != bird->collision[h].x)
            h++;
        if (enemy->enemy_pos.x == bird->collision[h].x)
            h = d + 100;
    }
    if (h <= 40) {
        bird->collision[d] = enemy->enemy_pos;
        d++;
    }
}

void place_obstacles(enemy_t *enemy, map_t *buff)
{
    static int x = 0;
    static int i = 0;

    if (buff->line[buff->lin_val][buff->char_val] == '2') {
        enemy->enemy_pos.x = enemy->enemy_pos.x;
        enemy->enemy_pos.y = (((buff->lin_val - 1) * 84) - 6);
        enemy->pos[x] = enemy->enemy_pos;
        x++;
    }
    if (buff->line[buff->lin_val][buff->char_val] == '3') {
        enemy->enemy_pos.x = enemy->enemy_pos.x;
        enemy->enemy_pos.y = (((buff->lin_val - 1) * 84) - 6);
        enemy->pos_d[i] = enemy->enemy_pos;
        i++;
    }
}

void place_obstacles_next(enemy_t *enemy, map_t *buff)
{
    static int f = 0;

    if (buff->line[buff->lin_val][buff->char_val] == '4') {
        enemy->enemy_pos.x = enemy->enemy_pos.x;
        enemy->enemy_pos.y = (((buff->lin_val - 1) * 84) - 6);
        enemy->pos_u[f] = enemy->enemy_pos;
        f++;
    }
}

void space_btw_pipe(enemy_t *enemy, map_t *buff)
{
    if (buff->line[buff->lin_val][buff->char_val] == '1' &&
        buff->line[buff->lin_val][buff->char_val + 1] == '\n') {
        enemy->limit = 750 - 50;
        enemy->enemy_pos.x = 1100;
    }
    if (buff->line[buff->lin_val][buff->char_val] == '\n' &&
        buff->line[buff->lin_val][buff->char_val - 1] != '1') {
        enemy->enemy_pos.y += 84;
        enemy->enemy_pos.x = 1100;
    }
    if (buff->line[buff->lin_val][buff->char_val] ==
        ' ' && (buff->char_val % 8) != 0)
        enemy->enemy_pos.x = enemy->enemy_pos.x + 70;
}
