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

void get_instructions(void)
{
    //coordinates();
    dprintf(1, "Start_simulation\n");
    while (1) {
        dprintf(1, "GET_INFO_LIDAR\n");
        order_line();
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

void ai(void)
{
    get_instructions();
}