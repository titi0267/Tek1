/*
** EPITECH PROJECT, 2020
** bird jump's by Timothy CONIEL
** File description:
** bird_jump.c
*/
#include "../include/my.h"

void fall(player_t *bird, float delta_time)
{
    static float nbr = 0;

    if (nbr >= 0.01f) {
        bird->position.y = (4 * bird->fall_fast) + bird->position.y;
        nbr = 0;
    }
    nbr = delta_time + nbr;
}

void go_straight(player_t *bird)
{
    static int move_straight = 0;

    if (bird->while_jump == 2 && move_straight < 15) {
        move_straight++;
    }
    if (move_straight >= 15) {
        move_straight = 0;
        bird->while_jump = 0;
    }
}

void rotate(player_t *bird)
{
    static float rotate_speed = 1;

    if (bird->while_jump > 0 && bird->rotation > -20) {
        if (bird->rotation >= -20 && bird->rotation <= 30)
            rotate_speed -= 0.3f;
        if (bird->rotation > 30 && bird->rotation <= 100)
            rotate_speed -= 0.5f;
        if (bird->rotation >= 1)
            bird->rotation *= rotate_speed;
        if (bird->rotation < 1 && bird->rotation >= -20)
            bird->rotation -= 2;
        sfSprite_setRotation(bird->my_bird, bird->rotation);
    }
    if (bird->while_jump == 0 && bird->rotation <= 85) {
        bird->rotation += 2;
        bird->fall_fast += 0.03;
        sfSprite_setRotation(bird->my_bird, bird->rotation);
        rotate_speed = 1;
    }
}

void jump(player_t *bird)
{
    static int jump_limit = 0;

    if (bird->while_jump == 1 && jump_limit < 15) {
        jump_limit++;
        bird->position.y -= 6;
        if (bird->second_jump > 1) {
            bird->second_jump--;
            jump_limit = 0;
        }
        bird->fall_fast = 1;
    }
    if (jump_limit == 15) {
        jump_limit = 0;
        bird->while_jump = 2;
    }
    go_straight(bird);
    rotate(bird);
}