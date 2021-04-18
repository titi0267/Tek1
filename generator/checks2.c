/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** checks_2.c
*/

#include "include/dante.h"

void check_impossible(maze_t *maze, int i, int d)
{
    if (i == 0) {
        maze->up = 1;
    }
    if (i == maze->height) {
        maze->down = 1;
    }
    if (d == 0) {
        maze->left = 1;
    }
    if (d == maze->width) {
        maze->right = 1;
    }
    maze->check = 1;
}

pos_t *check_visit(maze_t *maze, pos_t *pos)
{
    int i = maze->pos_x;
    int d = maze->pos_y;

    maze->rand_nb = rand() % 4;
    if (maze->check == 0)
        check_impossible(maze, i, d);
    if (maze->rand_nb == 0)
        pos = check_up(maze, i, d, pos);
    else if (maze->rand_nb == 1)
        pos = check_down(maze, i, d, pos);
    else if (maze->rand_nb == 2)
        pos = check_left(maze, i, d, pos);
    else
        pos = check_right(maze, i, d, pos);
    pos = all_visited(maze, pos, i, d);
    return (pos);
}

pos_t *all_visited(maze_t *maze, pos_t *pos, int i, int d)
{
    if ((maze->up + maze->down + maze->left + maze->right) == 4
        && maze->success != 1) {
        pos = pop(&pos, maze);
    } else if (maze->success == 1) {
        maze->failed = 0;
        maze->up = 0;
        maze->down = 0;
        maze->left = 0;
        maze->right = 0;
        maze->success = 0;
        maze->prevprevprev_rand = maze->prevprev_rand;
        maze->prevprev_rand = maze->prev_rand;
        maze->prev_rand = maze->rand_nb;
    }
    return (pos);
}