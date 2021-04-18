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
#include "struct.h"

int error_handler(int, char **, maze_t *);
void push(pos_t **, int, int, maze_t *);
pos_t *pop(pos_t **, maze_t *);
void print_list(pos_t **head);
void empty_maze(char **av, maze_t *maze);
void init_unvisit(maze_t *maze);
pos_t *up_visit(maze_t *, int, int, pos_t *);
pos_t *down_visit(maze_t *maze, int i, int d, pos_t *pos);
pos_t *left_visit(maze_t *, int, int, pos_t *);
pos_t *right_visit(maze_t *, int, int, pos_t *);

#endif /* !DANTE_H_ */