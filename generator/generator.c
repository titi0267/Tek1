/*
** EPITECH PROJECT, 2021
** generator main
** File description:
** generator.c
*/

#include "include/dante.h"

void all_visited(maze_t *maze, pos_t *pos, int i, int d)
{
    if (maze->failed == 4 && maze->success != 1) {
        pop(&pos, maze);
    } else if (maze->success == 1) {
        maze->failed = 0;
        maze->up = 0;
        maze->down = 0;
        maze->left = 0;
        maze->right = 0;
        maze->success = 0;
    }
}

void check_impossible(maze_t *maze, int i, int d)
{
    if (i == 0) {
        maze->failed++;
        maze->up = 1;
    }
    if (i == maze->height) {
        maze->failed++;
        maze->down = 1;
    }
    if (d == 0) {
        maze->failed++;
        maze->left = 1;
    }
    if (d == maze->width) {
        maze->failed++;
        maze->right = 1;
    }
    maze->check = 1;
}

void check_visit(maze_t *maze, pos_t *pos)
{
    int r = rand() % 4;
    int i = maze->pos_x;
    int d = maze->pos_y;

    if (maze->check == 0)
        check_impossible(maze, i, d);
    my_printf("random = %i, up = %i, down = %i, left = %i, right = %i\n", r, maze->up, maze->down, maze->left, maze->right);
    my_printf("fail = %i\n", maze->failed);
    if (r == 0 && maze->up != 1 && (i > 0 && i <= maze->height) && maze->visit[i - 1][d] != visited) {
        my_printf("in UP\n");
        up_visit(maze, i - 1, d, pos);
    }
    if (r == 1 && maze->down != 1 && (i >= 0 && i < maze->height - 1) && maze->visit[i + 1][d] != visited) {
        my_printf("Go down\n");
        down_visit(maze, i + 1, d, pos);
    }
    if (r == 2 && maze->left != 1 && (d > 0 && d <= maze->width) && maze->visit[i][d - 1] != visited) {
        my_printf("Go left\n");
        left_visit(maze, i, d - 1, pos);
    }
    if (r == 3 && maze->right != 1 && (d >= 0 && d < maze->width) && maze->visit[i][d + 1] != visited) {
        my_printf("In Right\n");
        right_visit(maze, i, d + 1, pos);
    }
    all_visited(maze, pos, i, d);
}

void forward_maze(maze_t *maze)
{
    pos_t *pos = NULL;

    maze->pos_x = 0;
    maze->pos_y = 0;
    push(&pos, maze->pos_x, maze->pos_y, maze);
    maze->success = 0;
    srand(time(NULL));
    while (pos != NULL) {
        check_visit(maze, pos);
        my_printf("\n");
        for (int i = 0; maze->visit[i] != NULL; i++) {
            for (int d = 0; maze->visit[i][d] != -1; d++)
                my_printf("%i", maze->visit[i][d]);
            my_printf("\n");
        }
    }
}

void linked_list(maze_t *maze)
{
    pos_t *pos = NULL;

    push(&pos, 1, 2, maze);
    push(&pos, 3, 4, maze);
    push(&pos, 5, 6, maze);
    push(&pos, 7, 8, maze);
    print_list(&pos);
    pop(&pos, maze);
    print_list(&pos);
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
    /*for (int i = 0; maze->visit[i] != NULL; i++) {
        for (int d = 0; maze->visit[i][d] != -1; d++)
            my_printf("%i", maze->visit[i][d]);
        my_printf("\n");
    }*/
    forward_maze(maze);
    /*for (int i = 0; maze->visit[i] != NULL; i++) {
        for (int d = 0; maze->visit[i][d] != -1; d++)
            my_printf("%i", maze->visit[i][d]);
        my_printf("\n");
    }*/
    //linked_list(maze);
    return (0);
}
