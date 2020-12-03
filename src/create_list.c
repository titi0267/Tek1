/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-timothe.coniel
** File description:
** create_list
*/
#include <stdlib.h>
#include "../include/my.h"

int insert(struct list_t **list, int new_nbr)
{
    struct list_t *element = malloc(sizeof(*element));

    if (element == NULL)
        return (84);
    element->nbr = new_nbr;
    element->next = *list;
    *list = element;
    return (0);
}

void delete(struct list_t *list)
{
    struct list_t *delete;

    while (list != NULL) {
        delete = list;
        list = list->next;
        free(delete);
    }
}

void print_list(struct list_t *list)
{
    struct list_t *tmp;

    tmp = list;
    while (tmp != NULL) {
        my_putnbr(tmp->nbr);
        my_putchar('\n');
        tmp = tmp->next;
    }
}

int sort_all(struct list_t **list, struct seclist_t **list_b, in_b_t *value)
{
    struct list_t *element = *list;

    while (*list != NULL) {
        max_val(list, list_b, value);
    }
}