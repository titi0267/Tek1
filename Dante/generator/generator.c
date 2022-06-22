/*
** EPITECH PROJECT, 2021
** generator main
** File description:
** generator.c
*/

#include "include/dante.h"

int loop(pos_t **head)
{
    if ((*head) == NULL)
        return (1);
    return (0);
}

void forward_maze(maze_t *maze)
{
    pos_t *pos = NULL;

    maze->pos_x = 0;
    maze->pos_y = 0;
    push(&pos, maze->pos_x, maze->pos_y, maze);
    maze->success = 0;
    srand(time(NULL));
    while (1) {
        pos = check_visit(maze, pos);
        if (loop(&pos) == 1)
            break;
    }
}

void my_freeing(maze_t *maze)
{
    for (int x = 0; maze->maze[x]; x++) {
        free(maze->maze[x]);
        free(maze->visit[x]);
    }
    free(maze->maze);
    free(maze->visit);
    free(maze);
}

void put_in_tabchar(maze_t *maze)
{
    int x = 0;
    int y = 0;
    int backline = 0;

    for (; maze->visit[x]; x++) {
        for (y = 0; maze->visit[x][y] != -1; y++) {
            if (maze->visit[x][y] == 0)
                maze->maze[x][y] = 'X';
            else if (maze->visit[x][y] == 1)
                maze->maze[x][y] = '*';
        }
        maze->maze[x][y] = '\0';
        if (backline != 0)
            my_printf("\n%s", maze->maze[x]);
        else
            my_printf("%s", maze->maze[x]);
        backline = 1;
    }
    maze->maze[x] = NULL;
}

int main(int ac, char **av)
{
    maze_t *maze = malloc(sizeof(maze_t));

    if (maze == NULL) exit(84);
    if (error_handler(ac, av, maze) == 84) {
        free(maze);
        return (84);
    }
    empty_maze(av, maze);
    init_unvisit(maze);
    forward_maze(maze);
    replace_last_ln(maze);
    put_in_tabchar(maze);
    my_freeing(maze);
    return (0);
}
