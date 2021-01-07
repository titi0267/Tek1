/*
** EPITECH PROJECT, 2020
** collision by Timothy CONIEL
** File description:
** collision.c
*/
#include "../include/my.h"

void limit(enemy_t *enemy, player_t *bird)
{
    if (bird->position.y >= enemy->limit) {
        bird->position.y = 700;
        bird->death = 1;
    }
}

void collision(player_t *bird)
{
    static int i = 1;

    while (i <= 16) {
        bird->collision[i].x -= 4;
        i++;
    }
    i = 1;
}

void bird_pass(gather_t *gather)
{
    static int h = 1;

    while (h <= 16) {
        if (gather->bird.collision[h].x < (gather->bird.position.x + 60) &&
            gather->bird.collision[h].x > (gather->bird.position.x - 84))
            break;
        h++;
    }
    if (h != 17) {
        if ((gather->bird.collision[h].y + 12) < gather->bird.position.y &&
            gather->bird.collision[h].y + ((84 * 2) - 6) > (gather->bird.position.y + 42.7f)) {
            gather->bird.high = 1;
        } else
            gather->bird.high = 0;
    }
    if (h == 17) {
        gather->bird.high = 1;
    }
    if (gather->bird.high == 0)
        gather->bird.death = 1;
    h = 1;
}