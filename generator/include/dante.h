/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-dante-timothe.coniel
** File description:
** dante
*/

#ifndef DANTE_H_
#define DANTE_H_

typedef struct data_s {
    int maze_width;
    int maze_heigth;
} data_t;

int error_handler(int, char **);

#endif /* !DANTE_H_ */