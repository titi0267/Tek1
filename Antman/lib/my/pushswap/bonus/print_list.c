/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-timothe.coniel
** File description:
** print_list
*/
#include "../include/my.h"
#include <stdlib.h>

void print_alist(struct list_t *list, int *arr)
{
    int i = 0;
    struct list_t *tmp = list;

    while (tmp != NULL) {
        arr[i] = tmp->nbr;
        tmp = tmp->next;
        i++;
    }
    arr[i] = 0;
}

int print_blist(struct seclist_t *list_b, struct list_t *list)
{
    struct seclist_t *tmp = list_b;

    my_putstr("Here strat second list :\n");
    while (tmp != NULL) {
        my_putnbr(tmp->num);
        my_putchar('\n');
        tmp = tmp->next;
    }
    return (0);
}
