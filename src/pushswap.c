/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-timothe.coniel
** File description:
** pushswap
*/

#include "../include/my.h"
#include <stdlib.h>
#include <unistd.h>

void size_a(struct list_t **list, in_b_t *value)
{
    struct list_t *element = *list;
    int i = 0;
    value->low = element->nbr;

    value->size = 0;
    while (element->next != NULL) {
        if (value->low > element->next->nbr)
            value->low = element->next->nbr;
        element = element->next;
    }
    while (element != NULL) {
        element = element->next;
        value->size++;
    }
    value->store_size = value->size;
}

void push_low_front(struct list_t **list, struct seclist_t **list_b, in_b_t *value)
{
    struct list_t *element = *list;

    while ((*list)->nbr != value->low) {
        ra(list, list_b, value);
        write(1, "ra ", 3);
    }
    pb(list_b, list);
    write(1, "pb ", 3);
}

void push_a(struct list_t **list, struct seclist_t **list_b, in_b_t *value)
{
    struct seclist_t *element = *list_b;

    while ((*list_b)->next != NULL) {
        if ((*list_b)->num < (*list_b)->next->num) {
            sb(list_b);
            pa(list_b, list);
            write(1, "sb pa ", 6);
        } else if ((*list_b)->num >= (*list_b)->next->num) {
            pa(list_b, list);
            write(1, "pa ", 3);
        }
    }
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

void push_b(struct list_t **list, struct seclist_t **list_b, in_b_t *value)
{
    struct list_t *element = *list;

    while ((*list)->next != NULL) {
        if ((*list)->nbr > (*list)->next->nbr) {
            sa(list);
            pb(list_b, list);
            write(1, "sa pb ", 6);
        } else if ((*list)->nbr <= (*list)->next->nbr) {
            pb(list_b, list);
            write(1, "pb ", 3);
        }
    }
}

void loop(struct list_t **list, struct seclist_t **list_b)
{
    in_b_t *value = malloc(sizeof(in_b_t));

    size_a(list, value);
    if (sorted(list, list_b, value) == 0)
        write(1, "\n", 1);
    else
        push_low_front(list, list_b, value);
    while (sorted(list, list_b, value) == -1) {
        push_b(list, list_b, value);
        push_a(list, list_b, value);
    }
    if ((*list_b) != NULL) {
        pa(list_b, list);
        write(1, "pa\n", 3);
    }
    free(value);
}
