/*
** EPITECH PROJECT, 2021
** generator main
** File description:
** generator.c
*/

#include "include/dante.h"

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
    }
    return (pos);
}

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
    int r = rand() % 4;
    int i = maze->pos_x;
    int d = maze->pos_y;

    if (maze->check == 0)
        check_impossible(maze, i, d);
    if (r == 0) {
        if (maze->up != 1 && (i > 0 && i <= maze->height) && maze->visit[i - 1][d] != visited) {
            pos = up_visit(maze, i - 1, d, pos);
        } else {
            maze->up = 1;
        }
    }
    if (r == 1) {
        if (maze->down != 1 && (i >= 0 && i < maze->height - 1) && maze->visit[i + 1][d] != visited) {
            pos = down_visit(maze, i + 1, d, pos);
        } else {
            maze->down = 1;
        }
    }
    if (r == 2) {
        if (maze->left != 1 && (d > 0 && d <= maze->width) && maze->visit[i][d - 1] != visited) {
            pos = left_visit(maze, i, d - 1, pos);
        } else {
            maze->left = 1;
        }
    }
    if (r == 3) {
        if (maze->right != 1 && (d >= 0 && d < maze->width - 1) && maze->visit[i][d + 1] != visited) {
            pos = right_visit(maze, i, d + 1, pos);
        } else {
            maze->right = 1;
        }
    }
    pos = all_visited(maze, pos, i, d);
    return (pos);
}

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
    put_in_tabchar(maze);
    return (0);
}
