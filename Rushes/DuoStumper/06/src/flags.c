/*
** EPITECH PROJECT, 2021
** B-CPE-210-STG-2-1-stumper5-tom.nomine
** File description:
** base
*/

#include "my.h"

void free_all(stumper_t *stp)
{
    free(stp->car);
    free(stp->car_nbr);
    free(stp->str);
    free(stp->new_str);
}
