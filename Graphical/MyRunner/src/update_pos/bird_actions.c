/*
** EPITECH PROJECT, 2021
** bird actions by Timothy CONIEL
** File description:
** bird_actions.c
*/
#include "../../include/my.h"

void fall(player_t *bird, time_t *time)
{
    static float nbr = 0;

    if (nbr >= 0.01f) {
        bird->position.y = (4 * bird->fall_fast) + bird->position.y;
        nbr = 0;
    }
    nbr = time->delta_time + nbr;
}

void go_straight(player_t *bird)
{
    static int move_straight = 0;

    if (bird->while_jump == 2 && move_straight < 15)
        move_straight++;
    if (move_straight >= 15) {
        move_straight = 0;
        bird->while_jump = 0;
    }
}

void rotate(player_t *bird)
{
    if (bird->while_jump > 0 && bird->rotation > -20) {
        if (bird->rotation >= -20 && bird->rotation <= 30)
            bird->rotate_speed -= 0.3f;
        if (bird->rotation > 30 && bird->rotation <= 100)
            bird->rotate_speed -= 0.5f;
        if (bird->rotation >= 1)
            bird->rotation *= bird->rotate_speed;
        if (bird->rotation < 1 && bird->rotation >= -20)
            bird->rotation -= 2;
        sfSprite_setRotation(bird->my_bird, bird->rotation);
    }
    if (bird->while_jump == 0 && bird->rotation <= 85) {
        bird->rotation += 2;
        bird->fall_fast += 0.03;
        sfSprite_setRotation(bird->my_bird, bird->rotation);
        bird->rotate_speed = 1;
    }
}

void jump(player_t *bird)
{
    static int jump_limit = 0;

    if (bird->while_jump == 1 && jump_limit < 15) {
        jump_limit++;
        bird->position.y -= 5;
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

void bird_action(gather_t *gather)
{
    if (gather->bird.while_jump == 0)
        fall(&gather->bird, &gather->time);
    jump(&gather->bird);
    limit(&gather->enemy, &gather->bird);
    if (gather->bird.high == 0)
        gather->bird.death = 1;
}
