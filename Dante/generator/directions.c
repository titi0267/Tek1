/*
** EPITECH PROJECT, 2021
** directions
** File description:
** directions.c
*/

#include "include/dante.h"

pos_t *left(pos_t *pos, maze_t *maze)
{
    if ((maze->pos_y <= 1 || maze->visit[maze->pos_x][maze->pos_y - 2]
    == unvisited) && (maze->pos_x >= (maze->height - 1) ||
    maze->visit[maze->pos_x + 1][maze->pos_y - 1] == unvisited) && (maze->pos_x
    <= 0 || maze->visit[maze->pos_x - 1][maze->pos_y - 1] == unvisited)) {
        maze->pos_y -= 1;
        push(&pos, maze->pos_x, maze->pos_y, maze);
        maze->visit[maze->pos_x][maze->pos_y] = visited;
    } else
        maze->left = 1;
    return (pos);
}

pos_t *right(pos_t *pos, maze_t *maze)
{
    if ((maze->pos_y >= (maze->width - 2) ||
    maze->visit[maze->pos_x][maze->pos_y + 2] == unvisited) && (maze->pos_x >=
    (maze->height - 1) || maze->visit[maze->pos_x + 1][maze->pos_y + 1]
    == unvisited) && (maze->pos_x <= 0 ||
    maze->visit[maze->pos_x - 1][maze->pos_y + 1] == unvisited)) {
        maze->pos_y += 1;
        push(&pos, maze->pos_x, maze->pos_y, maze);
        maze->visit[maze->pos_x][maze->pos_y] = visited;
    } else
        maze->right = 1;
    return (pos);
}

pos_t *up(pos_t *pos, maze_t *maze)
{
    if ((maze->pos_x <= 1 || maze->visit[maze->pos_x - 2][maze->pos_y] ==
    unvisited) && (maze->pos_y <= 0 ||
    maze->visit[maze->pos_x - 1][maze->pos_y - 1] == unvisited) && (maze->pos_y
    >= (maze->width - 1) || maze->visit[maze->pos_x - 1][maze->pos_y + 1]
    == unvisited)) {
        maze->pos_x -= 1;
        push(&pos, maze->pos_x, maze->pos_y, maze);
        maze->visit[maze->pos_x][maze->pos_y] = visited;
    } else
        maze->up = 1;
    return (pos);
}

pos_t *down(pos_t *pos, maze_t *maze)
{
    if ((maze->pos_x >= (maze->height - 2) ||
    maze->visit[maze->pos_x + 2][maze->pos_y] == unvisited) && (maze->pos_y <= 0
    || maze->visit[maze->pos_x + 1][maze->pos_y - 1] == unvisited) &&
    (maze->pos_y >= (maze->width - 1) ||
    maze->visit[maze->pos_x + 1][maze->pos_y + 1] == unvisited)) {
        maze->pos_x += 1;
        push(&pos, maze->pos_x, maze->pos_y, maze);
        maze->visit[maze->pos_x][maze->pos_y] = visited;
    } else
        maze->down = 1;
    return (pos);
}
