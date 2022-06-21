/*
** EPITECH PROJECT, 2020
** annex.c by Timothé CONIEL & Elliot WALDVOGEL
** File description:
** annex
*/

#include "../include/my_struct.h"
#include "../include/my.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void velocity(infin_number_t *info)
{
    int c = 3;
    int a = 0;
    float f = 0;

    for (;c < 8 && a < 3; a ++, c ++) {
        if (c == 3 && a == 0) {
            f = info->given[c] - info->given[a];
            info->vels[a] = f;
        }
        if (c == 4 && a == 1) {
            f = info->given[c] - info->given[a];
            info->vels[a] = f;
        }
        if (c == 5 && a == 2) {
            f = info->given[c] - info->given[a];
            info->vels[a] = f;
        }
    }
}

void nextpos(infin_number_t *info)
{
    int c = 3;
    int a = 0;
    float f = 0;

    for (;c < 8 && a < 3; c ++, a ++) {
        if (c == 3 && a == 0) {
            f = (info->given[6] * info->vels[a]) + info->given[c];
            info->tpos[a] = f;
        }
        if (c == 4 && a == 1) {
            f = (info->given[6] * info->vels[a]) + info->given[c];
            info->tpos[a] = f;
        }
        if (c == 5 && a == 2) {
            f = (info->given[6] * info->vels[a]) + info->given[c];
            info->tpos[a] = f;
        }
    }
}

int bouncing(infin_number_t *info)
{
    if ((info->given[2] > info->given[5] && info->given[5] > 0) || 
        (info->given[2] < info->given[5] && info->given[5] < 0))
        return (1);
    else
        return (0);
}

int angle(infin_number_t *info)
{
    float f;
    float radian;
    float degree;

    f = sqrt(pow(info->vels[0], 2) + pow(info->vels[1], 2) + pow(info->vels[2], 2));
    if (f == 0)
        return (84);
    if (f != 0) {
        radian = asinf(info->vels[2]/f);
        degree = radian * (180/3.14159);
    }
    if (degree < 0)
        degree *= -1;
    info->angle = degree;
    return (0);
}

void core101(infin_number_t *info)
{
    velocity(info);
    nextpos(info);
    info->bounced = bouncing(info);
    info->c_error = angle(info);
    if (info->bounced == 1 && info->c_error == 0 && info->vels[2] != 0)
        angle(info);
}