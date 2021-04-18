/*
** EPITECH PROJECT, 2021
** linked list
** File description:
** linked_list.c
*/

#include "include/dante.h"

void push(pos_t **head, int x, int y, maze_t *maze)
{
    pos_t *new = malloc(sizeof(pos_t));

    my_printf("times\n");
    maze->up = 0;
    maze->down = 0;
    maze->left = 0;
    maze->right = 0;
    maze->failed = 0;
    maze->success = 1;
    maze->check = 0;
    new->line = x;
    new->car = y;
    new->next = (*head);
    new->prev = NULL;
    if ((*head) != NULL)
        (*head)->prev = new;
    (*head) = new;
}

int pop(pos_t **pos, maze_t *maze)
{
    pos_t *rm = (*pos);

    if (rm == NULL)
        return (0);
    (*pos) = (*pos)->next;
    if ((*pos) == NULL)
        return (0);
    maze->up = 0;
    maze->down = 0;
    maze->left = 0;
    maze->right = 0;
    maze->failed = 0;
    maze->check = 0;
    maze->pos_x = (*pos)->line;
    maze->pos_y = (*pos)->car;
    free(rm);
    return (0);
}

void print_list(pos_t **head)
{
    pos_t *node = (*head);

    for (; node != NULL; node = node->next)
        printf("line = %d & car = %d\n", node->line, node->car);
}
