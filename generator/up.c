/*
** EPITECH PROJECT, 2021
** up
** File description:
** up.c
*/

#include "include/dante.h"

void up_special(maze_t *maze, int i, int d, pos_t *pos)
{
    if (d != 0 && d != maze->width && maze->visit[i][d - 1] != visited &&
        maze->visit[i][d + 1] != visited) {
        maze->visit[i][d] = visited;
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
    } else if (d == 0 && maze->visit[i][d + 1] != visited) {
        maze->visit[i][d] = visited;
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
    } else if (d == maze->width && maze->visit[i][d - 1] != visited) {
        maze->visit[i][d] = visited;
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
    }
}

void up_special_zero(maze_t *maze, int i, int d, pos_t *pos)
{
    if (i != 0 && maze->visit[i - 1][d] != visited &&
        maze->visit[i][d + 1] != visited) {
        maze->visit[i][d] = visited;
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
    } else if (i == 0 && maze->visit[i][d + 1] != visited) {
        maze->visit[i][d] = visited;
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
    }
}

void up_special_end(maze_t *maze, int i, int d, pos_t *pos)
{
    if (i != 0 && maze->visit[i - 1][d] != visited &&
        maze->visit[i][d - 1] != visited) {
        maze->visit[i][d] = visited;
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
    } else if (i == 0 && maze->visit[i][d - 1] != visited) {
        maze->visit[i][d] = visited;
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
    }
}

void up_visit(maze_t *maze, int i, int d, pos_t *pos)
{
    if (i != 0 && d != 0 && d != maze->width) {
        my_printf("in up if\n");
        if (maze->visit[i][d - 1] != visited && maze->visit[i][d + 1] != visited
            && maze->visit[i + 1][d] != visited) {
            maze->visit[i][d] = visited;
            push(&pos, i, d, maze);
            maze->pos_x = i;
            maze->pos_y = d;
        }
    } else if (i == 0)
        up_special(maze, i, d, pos);
    else if (d == 0)
        up_special_zero(maze, i, d, pos);
    else if (d == maze->width)
        up_special_end(maze, i, d, pos);
    maze->up = 1;
    maze->failed++;
}
