/*
** EPITECH PROJECT, 2021
** down
** File description:
** down.c
*/

#include "include/dante.h"

void down_special(maze_t *maze, int i, int d, pos_t *pos)
{
    if (d != 0 && d != maze->width && maze->visit[i][d - 1] != visited &&
        maze->visit[i][d + 1] != visited) {
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
        maze->visit[i][d] = visited;
    } else if (d == maze->width && maze->visit[i][d - 1] != visited) {
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
        maze->visit[i][d] = visited;
    } else if (d == 0 && maze->visit[i][d + 1] != visited) {
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
        maze->visit[i][d] = visited;
    }
}

void down_special_zero(maze_t *maze, int i, int d, pos_t *pos)
{
    //my_printf("\nheight = %i & i = %i\n", maze->height, maze->visit[i + 1][d]);
    if (i != maze->height && maze->visit[i + 1][d] != visited &&
        maze->visit[i][d + 1] != visited) {
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
        maze->visit[i][d] = visited;
    } else if (i == maze->height && maze->visit[i][d + 1] != visited) {
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
        maze->visit[i][d] = visited;
    }
}

void down_special_end(maze_t *maze, int i, int d, pos_t *pos)
{
    if (i != maze->height && maze->visit[i + 1][d] != visited &&
        maze->visit[i][d - 1] != visited) {
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
        maze->visit[i][d] = visited;
    } else if (i == maze->height && maze->visit[i][d - 1] != visited) {
        push(&pos, i, d, maze);
        maze->pos_x = i;
        maze->pos_y = d;
        maze->visit[i][d] = visited;
    }

}

void down_visit(maze_t *maze, int i, int d, pos_t *pos)
{
    if (i != maze->height && d != 0 && d != maze->width) {
        if (maze->visit[i][d - 1] != visited
        && maze->visit[i][d + 1] != visited
        && maze->visit[i - 1][d] != visited) {
            maze->visit[i][d] = visited;
            push(&pos, i, d, maze);
            maze->pos_x = i;
            maze->pos_y = d;
        }
    } else if (i == maze->height)
        down_special(maze, i, d, pos);
    else if (d == 0)
        down_special_zero(maze, i, d, pos);
    else if (d == maze->width)
        down_special_end(maze, i, d, pos);
    maze->down = 1;
    maze->failed++;
}
