/*
** EPITECH PROJECT, 2021
** create maze
** File description:
** create_maze.c
*/

#include "include/dante.h"

void empty_maze(char **av, maze_t *maze)
{
    int d = 0;
    int i = 0;

    if ((maze->maze = malloc(sizeof(char *) * (maze->height + 1))) == NULL)
        exit(84);
    for (; i < maze->height; i++) {
        maze->maze[i] = malloc(sizeof(char) * maze->width + 1);
        for (; d < maze->width; d++)
            maze->maze[i][d] = '*';
        maze->maze[i][d] = '\0';
        d = 0;
    }
    maze->maze[i] = NULL;
}

void init_unvisit(maze_t *maze)
{
    if ((maze->visit = malloc(sizeof(int *) * (maze->height + 1))) == NULL) exit(84);
    for (int i = 0; i < maze->height; i++) {
        if ((maze->visit[i] = malloc(sizeof(int) * (maze->width + 1))) == NULL)
            exit(84);
        for (int d = 0; d < maze->width; d++)
            maze->visit[i][d] = unvisited;
        maze->visit[i][maze->width] = -1;
    }
    maze->visit[maze->height] = NULL;
    maze->visit[0][0] = visited;
}
