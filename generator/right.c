/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** right.c
*/

#include "include/dante.h"

pos_t *right_special(maze_t *maze, int i, int d, pos_t *pos)
{
    if (i != 0 && i != maze->height -1 && maze->visit[i + 1][d] != visited
    && maze->visit[i - 1][d] != visited) {
        maze->visit[i][d] = visited;
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
    } else if (i == 0 && maze->visit[i + 1][d] != visited) {
        maze->visit[i][d] = visited;
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
    } else if (i == maze->height - 1 && maze->visit[i - 1][d] != visited) {
        maze->visit[i][d] = visited;
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
    }
    return (pos);
}

pos_t *right_special_zero(maze_t *maze, int i, int d, pos_t *pos)
{
    if (d != maze->width - 1 && maze->visit[i + 1][d] != visited &&
        maze->visit[i][d + 1] != visited) {
        maze->visit[i][d] = visited;
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
    } else if (d == maze->width - 1 && maze->visit[i + 1][d] != visited) {
        maze->visit[i][d] = visited;
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
    }
    return (pos);
}

pos_t *right_special_end(maze_t *maze, int i, int d, pos_t *pos)
{
    if (d != maze->width  - 1 && maze->visit[i - 1][d] != visited &&
        maze->visit[i][d + 1] != visited) {
        maze->visit[i][d] = visited;
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
    } else if (d == maze->width - 1 && maze->visit[i - 1][d] != visited) {
        maze->visit[i][d] = visited;
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
    }
    return (pos);
}

pos_t *right_visit(maze_t *maze, int i, int d, pos_t *pos)
{
    if (d != maze->width - 1 && i != 0 && i != maze->height - 1) {
        if (maze->visit[i][d + 1] != visited
        && maze->visit[i - 1][d] != visited
        && maze->visit[i + 1][d] != visited) {
            maze->visit[i][d] = visited;
            push(&pos, i, d, maze);
            maze->pos_x = i;
            maze->pos_y = d;
        }
    } else if (d == maze->width - 1)
        pos = right_special(maze, i, d, pos);
    else if (i == 0) {
        pos = right_special_zero(maze, i, d, pos);
    } else if (i == maze->height - 1)
        pos = right_special_end(maze, i, d, pos);
    maze->right = 1;
    return (pos);
}

// i + 1
// i - 1
// d + 1