/*
** EPITECH PROJECT, 2020
** my_struct for the infin_add.c project by Elliot WALDVOGEL
** File description:
** my_struct
*/

#ifndef MY_STRUCT_H_
#define MY_STRUCT_H_

typedef struct infin_number
{
    float given[8];
    float vels[4];
    float tpos[4];
    int bounced;
    float angle;
} infin_number_t;

#endif /* !MY_STRUCT_H_ */