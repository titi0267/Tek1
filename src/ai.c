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

    if (wall_right >= 600 && wall_left >= 600) {
        dprintf(1, "Car_forward:0.5\n");
        order_line(nfs);
        //dprintf(1, "Cycle_wait:1\n");
        //order_line(nfs);
        dprintf(2, "Tout droit (droite)\n");
        dprintf(1, "WHEELS_DIR:0.0\n");
        order_line(nfs);
    } else if (wall_right >= 300 && wall_left >= 300) {
        dprintf(1, "Car_forward:0.3\n");
        order_line(nfs);
        dprintf(1, "WHEELS_DIR:0.0\n");
        order_line(nfs);
    } else if (wall_right >= 150 && wall_right < wall_left) {
        dprintf(1, "Car_forward:0.2\n");
        order_line(nfs);
        //dprintf(1, "Cycle_wait:1\n");
        //order_line(nfs);
        dprintf(2, "droite est > 200 et > 400\n");
        dprintf(1, "WHEELS_DIR:0.1\n");
        order_line(nfs);
    } else if (wall_right >= 50 && wall_right < wall_left) {
        dprintf(1, "Car_forward:0.1\n");
        order_line(nfs);
        //dprintf(1, "Cycle_wait:1\n");
        //order_line(nfs);
        dprintf(2, "droite est > 100 et > 200\n");
        dprintf(1, "WHEELS_DIR:0.3\n");
        order_line(nfs);
    } else if (wall_right >= 0 && wall_right < wall_left) {
        dprintf(1, "Car_forward:0.1\n");
        order_line(nfs);
        //dprintf(1, "Cycle_wait:1\n");
        //order_line(nfs);
        dprintf(1, "WHEELS_DIR:1\n");
        order_line(nfs);
    }
}

void break_car(nfors_t *nfs)
{
    float wall_left = atof(nfs->my_tab[3]);
    float wall_right = atof(nfs->my_tab[33]);

    if (wall_left >= 600 && wall_left >= 600) {
        dprintf(1, "Car_forward:0.4\n");
        order_line(nfs);
        //dprintf(1, "Cycle_wait:1\n");
        //order_line(nfs);
        dprintf(2, "Tout droit (gauche)\n");
        dprintf(1, "WHEELS_DIR:0.0\n");
        order_line(nfs);
    } else if (wall_right >= 300 && wall_left >= 300) {
        dprintf(1, "Car_forward:0.3\n");
        order_line(nfs);
        dprintf(1, "WHEELS_DIR:0.0\n");
        order_line(nfs);
    } else if (wall_left >= 150 && wall_right > wall_left) {
        dprintf(1, "Car_forward:0.2\n");
        order_line(nfs);
        //dprintf(1, "Cycle_wait:1\n");
        dprintf(2, "gauche est > 200 et > 400\n");
        //order_line(nfs);
        dprintf(1, "WHEELS_DIR:-0.1\n");
        order_line(nfs);
    } else if (wall_left >= 50 && wall_right > wall_left) {
        dprintf(1, "Car_forward:0.1\n");
        order_line(nfs);
        //dprintf(1, "Cycle_wait:1\n");
        //order_line(nfs);
        dprintf(2, "gauche est < 200 et > 100\n");
        dprintf(1, "WHEELS_DIR:-0.5\n");
        order_line(nfs);
    } else if (wall_left >= 0 && wall_right > wall_left) {
        dprintf(1, "Car_forward:0.1\n");
        order_line(nfs);
        //dprintf(1, "Cycle_wait:1\n");
        //order_line(nfs);
        dprintf(1, "WHEELS_DIR:-1\n");
        order_line(nfs);
    }
    break_car_right(nfs);
}

void get_instructions(nfors_t *nfs)
{
    //coordinates();
    dprintf(1, "Start_simulation\n");
    while (1) {
        dprintf(1, "GET_INFO_LIDAR\n");
        order_line(nfs);
        if (nfs->tab_len >= 33)
            break_car(nfs);
        //stop_car(nfs);
        //order_line(nfs);
        //dprintf(1, "GET_CURRENT_SPEED\n");
        //printf("Cycle_wait:10\n");
    }
    // dprintf(1, "GET_INFO_LIDAR\n");
    // dprintf(1, "Cycle_wait:10\n");
    // dprintf(1, "GET_INFO_LIDAR\n");
    // dprintf(1, "Cycle_wait:10\n");
    // dprintf(1, "GET_INFO_LIDAR\n");
    // dprintf(1, "Cycle_wait:10\n");
    //wait(NULL);
}

void ai(nfors_t *nfs)
{
    get_instructions(nfs);
}