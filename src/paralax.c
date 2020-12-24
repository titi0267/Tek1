/*
** EPITECH PROJECT, 2020
** Scrolling_bakground by Timothy CONIEL
** File description:
** paralax.c
*/
#include "../include/my.h"

void init_background(background_t *back)
{
    back->position_back.x = 0;
    back->position_back.y = 0;
    back->pos_back.x = 1350;
    back->pos_back.y = 0;
    back->position_bott.x = 0;
    back->position_bott.y = 750;
    back->pos_bottom.x = 1350;
    back->pos_bottom.y = 750;
}

void background_paralax(background_t *back)
{
    static int t = 0;

    if (t >= -1350) {
        back->position_back.x = back->position_back.x - 1;
        back->pos_back.x = back->pos_back.x - 1;
        t--;
    }
    if (t == -1350) {
        t = 0;
        back->position_back.x = 0;
        back->pos_back.x = 1350;
    }
}

void bottom_paralax(background_t *back)
{
    static int t = 0;

    if (t >= -1350) {
        back->position_bott.x = back->position_bott.x - 1;
        back->pos_bottom.x = back->pos_bottom.x - 1;
        t--;
    }
    if (t == -1350) {
        t = 0;
        back->position_bott.x = 0;
        back->pos_bottom.x = 1350;
    }
}

void timer(float delta_time, background_t *back)
{
    static float b_ground = 0;
    static float bottom = 0;

    if (b_ground >= 0.03f) {
        background_paralax(back);
        b_ground = 0;
    }
    b_ground = delta_time + b_ground;
    if (bottom >= 0.001f) {
        bottom_paralax(back);
        bottom = 0;
    }
    bottom = delta_time + bottom;
}
