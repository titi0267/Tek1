/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-timothe.coniel
** File description:
** which_op
*/
#include "../include/my.h"
#include "../include/list.h"
#include <stdlib.h>
#include <unistd.h>

int rra(struct list_t **list) //last element become first
{
    struct list_t *last = *list;
    struct list_t *before_last = NULL;

    if (*list == NULL || (*list)->next == NULL) {
        my_putstr("You can't put the last element in 1st position because ");
        my_putstr("there are less than 2 elements\n");
        return (-1);
    }
    while (last->next != NULL) {
        before_last = last;
        last = last->next;
    }
    before_last->next = NULL;
    last->next = *list;
    *list = last;
    write(1, "rra ", 4);
    return (0);
}

int ra(struct list_t **list)
{
    struct list_t *first = *list;
    struct list_t *last = *list;

    if (*list == NULL) {
        my_putstr("You can't rotate first to the end because ");
        my_putstr("there are less than 1 elements\n");
        return (-1);
    }
    while (last->next != NULL) {
        last = last->next;
    }
    *list = first->next;
    first->next = NULL;
    last->next = first;
    write(1, "ra ", 3);
    return (0);
}

int sa(struct list_t **list)
{
    struct list_t *first = *list;

    if (*list == NULL ||(*list)->next == NULL) {
        my_putstr("You can't swap the first element with the second because ");
        my_putstr("there are less than 2 elements\n");
        return (-1);
    }
    first = first->next;
    (*list)->next = first->next;
    first->next = *list;
    *list = first;
    write(1, "sa ", 3);
    return (0);
}

int pa(struct seclist_t **list_b, struct list_t **list)
{
    struct list_t *element = malloc(sizeof(*element));
    struct seclist_t *first = *list_b;

    if (element == NULL)
        return (84);
    if (*list_b == NULL) {
        my_putstr("Not enough elements in b to push into a\n");
        return (-1);
    }
    element->nbr = first->num;
    element->next = *list;
    *list = element;
    *list_b = first->next;
    write(1, "pa ", 3);
    return (0);
}
