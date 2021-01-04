/*
** EPITECH PROJECT, 2020
** collision by Timothy CONIEL
** File description:
** collision.c
*/
#include "../include/my.h"

void limit(enemy_t *enemy, player_t *bird)
{
    static int d = 0;

    if (bird->position.y >= enemy->limit) {
        bird->position.y = 700;
        bird->death = 1;
    }
}

void collision(enemy_t *enemy, player_t *bird)
{
    static int i = 1;

    while (i <= 16) {
        bird->collision[i].x -= 4;
        i++;
    }
    i = 1;
}

void bird_pass(enemy_t *enemy, player_t *bird)
{
    static int h = 1;

    while (h <= 16) {
        if (bird->collision[h].x < (bird->position.x + 60) && bird->collision[h].x > (bird->position.x - 84))
            break;
        h++;
    }
    if (h != 17) {
        if ((bird->collision[h].y) < bird->position.y && bird->collision[h].y + (84 * 2) > (bird->position.y + 42.7f))
            bird->high = 1;
        else
            bird->high = 0;
    }
    if (h == 17)
        bird->high = 1;
    h = 1;
    if (bird->high == 0)
        bird->death = 1;
}