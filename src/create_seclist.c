/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-timothe.coniel
** File description:
** create_seclist
*/
#include "../include/my.h"
#include <stdlib.h>

void delete_b(struct seclist_t *list_b)
{
    struct seclist_t *delete;

    while (list_b != NULL) {
        delete = list_b;
        list_b = list_b->next;
        free(delete);
    }
}

int print_blist(struct seclist_t *list_b, struct list_t *list)
{
    struct seclist_t *tmp = list_b;

    while (tmp != NULL) {
        my_putnbr(tmp->num);
        my_putchar('\n');
        tmp = tmp->next;
    }
    return (0);
}
