/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-dante-timothe.coniel
** File description:
** dante
*/

#ifndef DANTE_H_
#define DANTE_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct data_s {
    char **maze;
    int maze_width;
    int maze_heigth;
    int error_status;
    int is_perfect;
} data_t;

int error_handler(int, char **, data_t *);

#endif /* !DANTE_H_ */