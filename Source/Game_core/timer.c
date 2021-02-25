/*
** EPITECH PROJECT, 2021
** timer by TImothy CONIEL & Tristan HOURTOUILLE
** File description:
** timer.c
*/

#include "../../include/defender.h"
#include <stdio.h>

void update_time(time_t *time)
{
    time->delta_time = sfClock_restart(time->clock).microseconds / 1000000.0;
    time->elapsed_time += time->delta_time;
    //printf("%2f\n", time->elapsed_time);
}

//1920/1080
//1280/720
//800/600