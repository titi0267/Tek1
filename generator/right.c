/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** right.c
*/

#include "include/dante.h"

void right_special(maze_t *maze, int i, int d, pos_t *pos)
{
    if (i != 0 && i != maze->height && maze->visit[i + 1][d] != visited
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
    } else if (i == maze->height && maze->visit[i - 1][d] != visited) {
        maze->visit[i][d] = visited;
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
    }
}

void right_special_zero(maze_t *maze, int i, int d, pos_t *pos)
{
    if (d != maze->width && maze->visit[i + 1][d] != visited &&
        maze->visit[i][d + 1] != visited) {
        maze->visit[i][d] = visited;
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
    } else if (d == maze->width && maze->visit[i + 1][d] != visited) {
        maze->visit[i][d] = visited;
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
    }
}

void right_special_end(maze_t *maze, int i, int d, pos_t *pos)
{
    if (d != maze->width && maze->visit[i - 1][d] != visited &&
        maze->visit[i][d + 1] != visited) {
        maze->visit[i][d] = visited;
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
    } else if (d == maze->width && maze->visit[i - 1][d] != visited) {
        maze->visit[i][d] = visited;
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
    }
}

void right_visit(maze_t *maze, int i, int d, pos_t *pos)
{
    if (d != maze->width && i != 0 && i != maze->height) {
        if (maze->visit[i][d + 1] != visited
        && maze->visit[i - 1][d] != visited
        && maze->visit[i + 1][d] != visited) {
            maze->visit[i][d] = visited;
            push(&pos, i, d, maze);
            maze->pos_x = i;
            maze->pos_y = d;
        }
    } else if (d == maze->width)
        right_special(maze, i, d, pos);
    else if (i == 0)
        right_special_zero(maze, i, d, pos);
    else if (i == maze->height)
        right_special_end(maze, i, d, pos);
    maze->right = 1;
    maze->failed++;
}

// i + 1
// i - 1
// d + 1