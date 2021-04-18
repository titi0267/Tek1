/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** checks.c
*/

#include "include/dante.h"

pos_t *check_up(maze_t *maze, int i, int d, pos_t *pos)
{
    if (maze->up != 1 && (i >= 0 && i < maze->height - 1)
    && maze->visit[i - 1][d] != visited) {
        pos = up_visit(maze, i - 1, d, pos);
    } else {
        maze->up = 1;
    }
    return (pos);
}

pos_t *check_down(maze_t *maze, int i, int d, pos_t *pos)
{
    if (maze->down != 1 && (i >= 0 && i < maze->height - 1)
    && maze->visit[i + 1][d] != visited) {
        pos = down_visit(maze, i + 1, d, pos);
    } else {
        maze->down = 1;
    }
    return (pos);
}

pos_t *check_left(maze_t *maze, int i, int d, pos_t *pos)
{
    if (maze->left != 1 && (d >= 0 && d < maze->width - 1)
    && maze->visit[i][d - 1] != visited) {
        pos = left_visit(maze, i, d - 1, pos);
    } else {
        maze->left = 1;
    }
    return (pos);
}

pos_t *check_right(maze_t *maze, int i, int d, pos_t *pos)
{
    if (maze->right != 1 && (d >= 0 && d < maze->width - 1) &&
    maze->visit[i][d + 1] != visited) {
        pos = right_visit(maze, i, d + 1, pos);
    } else {
        maze->right = 1;
    }
    return (pos);
}