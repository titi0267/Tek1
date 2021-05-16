/*
** EPITECH PROJECT, 2021
** ai.c for n4s project by Maxime HOFFBECK, Timothy CONIEL & Elliot WALDOVGEL
** File description:
** ai
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../include/my.h"

void break_car_right(nfors_t *nfs)
{
    float wall_right = atof(nfs->my_tab[33]);
    float wall_left = atof(nfs->my_tab[3]);
    float wall_fr = atof(nfs->my_tab[19]);

    if (wall_right >= 800 && wall_left >= 800 && wall_fr >= 1250) {
        dprintf(1, "Car_forward:0.6\n");
        order_line(nfs);
        dprintf(1, "WHEELS_DIR:0.0\n");
        order_line(nfs);
    } else if (wall_right >= 450 && wall_left >= 450) {
        dprintf(1, "Car_forward:0.2\n");
        order_line(nfs);
        dprintf(1, "WHEELS_DIR:0.0\n");
        order_line(nfs);
    } else if (wall_right >= 250 && wall_right < wall_left) {
        dprintf(1, "Car_forward:0.15\n");
        order_line(nfs);
        dprintf(1, "WHEELS_DIR:0.2\n");
        order_line(nfs);
    } else if (wall_right >= 75 && wall_right < wall_left) {
        dprintf(1, "Car_forward:0.1\n");
        order_line(nfs);
        dprintf(1, "WHEELS_DIR:0.5\n");
        order_line(nfs);
    } else if (wall_right >= 0 && wall_right < wall_left) {
        dprintf(1, "Car_forward:0.05\n");
        order_line(nfs);
        dprintf(1, "WHEELS_DIR:1\n");
        order_line(nfs);
    }
}

void break_car(nfors_t *nfs)
{
    float wall_left = atof(nfs->my_tab[3]);
    float wall_right = atof(nfs->my_tab[33]);
    float wall_fr = atof(nfs->my_tab[19]);

    if (wall_left >= 800 && wall_left >= 800 && wall_fr >= 1250) {
        dprintf(1, "Car_forward:0.6\n");
        order_line(nfs);
        dprintf(1, "WHEELS_DIR:0.0\n");
        order_line(nfs);
    } else if (wall_right >= 450 && wall_left >= 450) {
        dprintf(1, "Car_forward:0.2\n");
        order_line(nfs);
        dprintf(1, "WHEELS_DIR:0.0\n");
        order_line(nfs);
    } else if (wall_left >= 250 && wall_right > wall_left) {
        dprintf(1, "Car_forward:0.15\n");
        order_line(nfs);
        dprintf(1, "WHEELS_DIR:-0.2\n");
        order_line(nfs);
    } else if (wall_left >= 75 && wall_right > wall_left) {
        dprintf(1, "Car_forward:0.1\n");
        order_line(nfs);
        dprintf(1, "WHEELS_DIR:-0.5\n");
        order_line(nfs);
    } else if (wall_left >= 0 && wall_right > wall_left) {
        dprintf(1, "Car_forward:0.05\n");
        order_line(nfs);
        dprintf(1, "WHEELS_DIR:-1\n");
        order_line(nfs);
    }
    break_car_right(nfs);
}

void get_instructions(nfors_t *nfs)
{
    dprintf(1, "Start_simulation\n");
    while (1) {
        dprintf(1, "GET_INFO_LIDAR\n");
        order_line(nfs);
        if (nfs->tab_len >= 33)
            break_car(nfs);
    }
}

void ai(nfors_t *nfs)
{
    get_instructions(nfs);
}