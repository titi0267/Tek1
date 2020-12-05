/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-timothe.coniel
** File description:
** op_seclist
*/
#include "../include/my.h"
#include <stdlib.h>
#include <unistd.h>

int rrb(struct seclist_t **list_b)
{
    struct seclist_t *last = *list_b;
    struct seclist_t *before_last = NULL;

    if (*list_b == NULL) {
        my_putstr("You can't put the last element in 1st position because ");
        my_putstr("there are less than 1 elements\n");
        return (-1);
    }
    while (last->next != NULL) {
        before_last = last;
        last = last->next;
    }
    before_last->next = NULL;
    last->next = *list_b;
    *list_b = last;
    write(1, "rrb ", 4);
    return (0);
}

int rb(struct seclist_t **list_b)
{
    struct seclist_t *first = *list_b;
    struct seclist_t *last = *list_b;

    if (*list_b == NULL) {
    my_putstr("You can't rotate the first to the end because ");
    my_putstr("there are less than 1 elements\n");
    return (-1);
    }
    while (last->next != NULL) {
        last = last->next;
    }
    *list_b = first->next;
    first->next = NULL;
    last->next = first;
    write(1, "rb ", 3);
    return (0);
}

int sb(struct seclist_t **list_b)
{
    struct seclist_t *first = *list_b;

    if (*list_b == NULL ||(*list_b)->next == NULL) {
        my_putstr("You can't swap the first element with the second because ");
        my_putstr("there are less than 2 elements\n");
        return (-1);
    }
    first = first->next;
    (*list_b)->next = first->next;
    first->next = *list_b;
    *list_b = first;
    write(1, "sb ", 3);
    return (0);
}

int pb(struct seclist_t **list_b, struct list_t **list)
{
    struct seclist_t *element = malloc(sizeof(*element));
    struct list_t *first = *list;

    if (element == NULL)
        return (84);
    if (*list == NULL) {
        my_putstr("There are less elements in a than you wants to push in b\n");
        return (-1);
    }
    element->num = first->nbr;
    element->next = *list_b;
    *list_b = element;
    *list = first->next;
    if (*list != NULL)
        write(1, "pb ", 3);
    else
        write(1, "pb\n", 3);
    return (0);
}
