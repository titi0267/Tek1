/*
** EPITECH PROJECT, 2021
** linked list
** File description:
** linked_list.c
*/

#include "include/dante.h"

void push(pos_t **head, int x, int y, maze_t *maze)
{
    pos_t *node = malloc(sizeof(pos_t));

    maze->up = 0;
    maze->down = 0;
    maze->left = 0;
    maze->right = 0;
    maze->success = 1;
    node->line = x;
    node->car = y;
    node->next = (*head);
    (*head) = node;
}

pos_t *pop(pos_t **pos, maze_t *maze)
{
    pos_t *rm = (*pos);

    maze->up = 0;
    maze->down = 0;
    maze->left = 0;
    maze->right = 0;
    if (rm == NULL)
        return (0);
    (*pos) = (*pos)->next;
    if ((*pos) == NULL)
        return (0);
    maze->pos_x = (*pos)->line;
    maze->pos_y = (*pos)->car;
    free(rm);
    return ((*pos));
}

void print_list(pos_t **pos)
{
    pos_t *node = (*pos);
    int i = 0;

    for (; node != NULL; node = node->next) {
        my_printf("visit[%i][%i] = %i\n", node->line, node->car, i);
        i++;
    }
}

void replace_last_ln(maze_t *maze)
{
    for (int i = maze->width - 1; i != 0; i--)  {
        if (maze->visit[maze->height - 2][i] == visited) {
            maze->visit[maze->height - 1][i] = visited;
            break;
        } else
            maze->visit[maze->height - 1][i] = visited;
    }
}