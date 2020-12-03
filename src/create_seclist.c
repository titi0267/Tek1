/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-timothe.coniel
** File description:
** create_seclist
*/
#include "../include/my.h"
#include <stdlib.h>

/*int insert_b(struct seclist_t **list_b, int new_num)
{
    struct seclist_t *element = malloc(sizeof(*element));

    if (element == NULL)
        return (84);
    element->num = new_num;
    element->next = *list_b;
    *list_b = element;
    return (0);
}*/

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
    struct seclist_t *tmp;

    tmp = list_b;
    //if (pb(&list_b, &list) == 84) {
    //    return (84);
    //}
    my_putstr("Here start the second list :\n");
    while (tmp != NULL) {
        my_putnbr(tmp->num);
        my_putchar('\n');
        tmp = tmp->next;
    }
    return (0);
}
