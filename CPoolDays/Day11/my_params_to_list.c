/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_params_to_list
*/
#include <stdlib.h>
#include <stdio.h>
#include "include/mylist.h"
#include "include/my.h"

int next_node(linked_list_t **list, char * const av)
{
    linked_list_t *new_node;

    new_node = malloc(sizeof(*new_node));
    new_node->data = av;
    new_node->next = *list;
    *list = new_node;
    return (0);
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *list;
    int i = 0;

    list = NULL;
    while (i < ac) {
        next_node(&list, av[i]);
        i ++;
        my_putstr(list->data);
    }
    return (list);
}