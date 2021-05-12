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

void get_instructions(char *str, size_t size_t)
{
    printf("Start_simulation\n");
    printf("GET_INFO_LIDAR\n");
    printf("Cycle_wait:0.000000000001\n");
    printf("Car_forward:1\n");
    printf("Cycle_wait:10\n");
    printf("GET_INFO_LIDAR\n");
    printf("Cycle_wait:10\n");
    printf("GET_INFO_LIDAR\n");
    printf("Cycle_wait:10\n");
    printf("GET_INFO_LIDAR\n");
    //coordinates(str, size_t);
    printf("Cycle_wait:10\n");
    //wait(NULL);
}

void ai(char *str, size_t size_t)
{
    get_instructions(str, size_t);
}