/*
** EPITECH PROJECT, 2021
** init bird by Timothy CONIEL
** File description:
** init_bird.c
*/
#include "../../include/my.h"

void init_pos_bird(player_t *bird)
{
    bird->position.x = 250;
    bird->position.y = 400;
    bird->rotation = 0;
    bird->anim.left = 0;
    bird->anim.top = 0;
    bird->anim.width = 173.666f;
    bird->anim.height = 122;
}

void bird_init(player_t *bird)
{
    init_pos_bird(bird);
    bird->offset = 0;
    bird->while_jump = 0;
    bird->second_jump = 0;
    bird->stop_jump = 0;
    bird->fall_fast = 1;
    bird->death = 0;
    bird->fit_space = 0;
    bird->high = 0;
    bird->fall_dead = 1;
    bird->angle_down = 1;
    bird->stop = 0;
}
