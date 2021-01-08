/*
** EPITECH PROJECT, 2020
** my_struct for the infin_add.c project by Elliot WALDVOGEL
** File description:
** my_struct
*/

#include <unistd.h>

#ifndef MY_STRUCT_H_
#define MY_STRUCT_H_

typedef struct infin_number_s
{
    int amount;
    int opt;
    int xp;
    int yp;
    int zp;
    int xv;
    int yv;
    int zv;
    int p;
} infin_number_t;

typedef struct sphere_s
{
    float delta;
    int a;
    int b;
    int c;
    int a_sqrt;
    int b_sqrt;
    int c_sqrt;
    int ax;
    int bx;
    int cx;
    int ay;
    int by;
    int cy;
    int az;
    int bz;
    int cz;
    float solution1;
    float solution2;
    float x;
    float y;
    float z;
    float x1;
    float y1;
    float z1;
} sphere_t;

typedef struct gather_s
{
    sphere_t *sphere;
    infin_number_t *info;
} gather_t;

#endif /* !MY_STRUCT_H_ */