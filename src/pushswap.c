/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-timothe.coniel
** File description:
** pushswap
*/

#include "../include/my.h"
#include <stdlib.h>
#include <stdio.h>

void size_a(struct list_t **list, in_b_t *value)
{
    struct list_t *element = *list;

    value->size = 0;
    while (element != NULL) {
        element = element->next;
        value->size++;
    }
    value->store_size = value->size;
}

int sorted(struct list_t **list, struct seclist_t **list_b, in_b_t *value)
{
    struct list_t *element = *list;

    while (element->next != NULL) {
        if (element->nbr > element->next->nbr)
            return (-1);
        element = element->next;
    }
    return (0);
}

int compare_a(struct list_t **list, struct seclist_t **list_b, in_b_t *value)
{
    struct list_t *element = *list;
    int i = 0;

    if (sorted(list, list_b, value) == -1) {
        while (value->size > 1) {
            if ((*list)->nbr > (*list)->next->nbr) {
                sa(list);
                ra(list, list_b, value);
            } else if ((*list)->nbr <= (*list)->next->nbr) {
                ra(list, list_b, value);
            }
            value->size--;
        }
        ra(list, list_b, value);
        value->size = value->store_size;
    }
    if (sorted(list, list_b, value) == 0) {
        return (1);
    }
    return (0);
}

void loop(struct list_t **list, struct seclist_t **list_b)
{
    in_b_t *value = malloc(sizeof(in_b_t));

    size_a(list, value);
    while (compare_a(list, list_b, value) == 0) {
        compare_a(list, list_b, value);
    }
    free(value);
}
