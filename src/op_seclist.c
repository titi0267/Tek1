/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-timothe.coniel
** File description:
** op_seclist
*/
#include "../include/my.h"
#include <stdlib.h>

int rrb(struct seclist_t **list_b)
{
    struct seclist_t *last = *list_b;
    struct seclist_t *before_last = NULL;

    if (*list_b == NULL || (*list_b)->next == NULL) {
        my_putstr("You can't put the last element in 1st position because ");
        my_putstr("there are less than 2 elements\n");
        return (-1);
    }
    while (last->next != NULL) {
        before_last = last;
        last = last->next;
    }
    before_last->next = NULL;
    last->next = *list_b;
    *list_b = last;
    return (0);
}

int rb(struct seclist_t **list_b)
{
    struct seclist_t *first = *list_b;
    struct seclist_t *last = *list_b;

    if (*list_b == NULL ||(*list_b)->next == NULL) {
    my_putstr("You can't swap the first element with the second because ");
    my_putstr("there are less than 2 elements\n");
    return (-1);
    }
    while (last->next != NULL) {
        last = last->next;
    }
    *list_b = first->next;
    first->next = NULL;
    last->next = first;
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
    return (0);
}
