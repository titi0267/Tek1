/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-timothe.coniel
** File description:
** pushswap
*/

#include "../include/my.h"
#include <stdlib.h>

void size_a(struct list_t **list, in_b_t *value)
{
    struct list_t *element = *list;

    value->size = 0;
    while (element != NULL) {
        element = element->next;
        value->size++;
    }
}

void compare_a(struct list_t **list, struct seclist_t **list_b, in_b_t *value)
{
    struct list_t *element;

        for (; value->size > 1; value->size--) {
            element = *list;
            if (element->nbr > (*list)->next->nbr)
                sa(list);
            if (element->nbr <= (*list)->next->nbr)
                ra(list);
        }
}


void loop(struct list_t **list, struct seclist_t **list_b)
{
    in_b_t *value = malloc(sizeof(in_b_t));
    int i = 0;

    size_a(list, value);
    while (*list != NULL) {
        while (value->size != 0) {
        value->store_size = value->size;
        compare_a(list, list_b, value);
        pb(list_b, list);
        i = value->store_size - 1;
        value->size = i;
        }
    }
    free(value);
}
