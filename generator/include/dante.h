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
pos_t *check_visit(maze_t *maze, pos_t *pos);
pos_t *all_visited(maze_t *maze, pos_t *pos);
pos_t *down(pos_t *pos, maze_t *maze);
pos_t *up(pos_t *pos, maze_t *maze);
pos_t *left(pos_t *pos, maze_t *maze);
pos_t *right(pos_t *pos, maze_t *maze);
#endif /* !DANTE_H_ */