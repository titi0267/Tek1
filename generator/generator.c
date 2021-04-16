/*
** EPITECH PROJECT, 2021
** generator main
** File description:
** generator.c
*/

#include "include/dante.h"

void push(pos_t **head, int x, int y)
{
    pos_t *new = malloc(sizeof(pos_t));

    new->line = x;
    new->car = y;
    new->next = (*head);
    new->prev = NULL;
    if ((*head) != NULL)
        (*head)->prev = new;
    (*head) = new;
}

void print_list(pos_t **head)
{
    pos_t* node = (*head);

    for (; node != NULL; node = node->next)
        printf("line = %d & car = %d\n", node->line, node->car);
}

int main(int ac, char **av)
{
    pos_t *pos = NULL;

    push(&pos, 2, 10);
    push(&pos, 1, 4);
    print_list(&pos);
    return (0);
}