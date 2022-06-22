/*
** EPITECH PROJECT, 2021
** init background by Timothy CONIEL
** File description:
** init_background.c
*/
#include "../../include/my.h"

void init_background(background_t *back)
{
    back->position_back.x = 0;
    back->position_back.y = 0;
    back->pos_back.x = 1350;
    back->pos_back.y = 0;
}

void init_bottom(background_t *back)
{
    back->position_bott.x = 0;
    back->position_bott.y = 750;
    back->pos_bottom.x = 1350;
    back->pos_bottom.y = 750;
}
