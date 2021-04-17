/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-dante-timothe.coniel
** File description:
** dante
*/

#ifndef DANTE_H_
#define DANTE_H_
#include "struct.h"
#include "../../include/my.h"
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct data_s {
    char **maze;
    int **tab;
    int maze_width;
    int maze_heigth;
    int error_status;
    int is_perfect;
} data_t;

int error_handler(int, char **, data_t *);
void my_freeing(data_t *data);

#endif /* !DANTE_H_ */