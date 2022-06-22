/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** checks_2.c
*/

#include "include/dante.h"

pos_t *all_visited(maze_t *maze, pos_t *pos)
{
    if ((maze->up + maze->down + maze->left + maze->right) == 4
        && maze->success != 1)
        pos = pop(&pos, maze);
    if (maze->success == 1) {
        maze->up = 0;
        maze->down = 0;
        maze->left = 0;
        maze->right = 0;
        maze->success = 0;
    }
    return (pos);
}

pos_t *check_left(maze_t *maze, pos_t *pos)
{
    if (maze->pos_y > 0 &&
    maze->visit[maze->pos_x][maze->pos_y - 1] == unvisited)
    pos = left(pos, maze);
    else
        maze->left = 1;
    return (pos);
}

pos_t *check_right(maze_t *maze, pos_t *pos)
{
    if (maze->pos_y < (maze->width - 1) &&
    maze->visit[maze->pos_x][maze->pos_y + 1] == unvisited)
        pos = right(pos, maze);
    else
        maze->right = 1;
    return (pos);
}

pos_t *check_up(maze_t *maze, pos_t *pos)
{
    if (maze->pos_x > 0 &&
    maze->visit[maze->pos_x - 1][maze->pos_y] == unvisited)
        pos = up(pos, maze);
    else
        maze->up = 1;
    return (pos);
}

pos_t *check_visit(maze_t *maze, pos_t *pos)
{
    maze->rand_nb = rand() % 4;
    if (maze->rand_nb == 0)
        pos = check_left(maze, pos);
    if (maze->rand_nb == 1)
        pos = check_right(maze, pos);
    if (maze->rand_nb == 2)
        pos = check_up(maze, pos);
    if (maze->rand_nb == 3) {
        if (maze->pos_x < (maze->height - 1) &&
        maze->visit[maze->pos_x + 1][maze->pos_y] == unvisited)
            pos = down(pos, maze);
        else
            maze->down = 1;
    }
    pos = all_visited(maze, pos);
    return (pos);
}