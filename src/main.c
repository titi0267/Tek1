/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-timothe.coniel
** File description:
** main
*/
#include "../include/my.h"
#include <stdlib.h>
#include <stdio.h>

int error(int ac, char **av)
{
    if (ac <= 1) {
        my_putstr("Nothing to put in the list\n");
        return (-1);
    }
    for (int i = 1; av[i] != 0; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (av[i][j] < 48 || av[i][j] > 57) {
                my_putstr("The list can only contain numbers\n");
                return (-1);
            }
        }
    }
    return (0);
}

/*int error_seclist(struct seclist_t *list_b, in_b_t *help)
{
    printf("Is was called : %i", help->call);
    while (help->call > 0) {
        help->call--;
    }
    print_blist(list_b);
    delete_b(list_b);
    return (0);
}*/

int main(int ac, char **av)
{
    struct list_t *my_list;
    struct seclist_t *my_seclist;
    in_b_t *help = malloc(sizeof(in_b_t));
    int x = error(ac, av);
    help->call = 0;

    my_list = NULL;
    my_seclist = NULL;
    int i = 1;
    if (x != 0)
        return (84);
    for (; av[i] != 0; i++) {
    //for (i = i - 1; i >= 1; i--) {
        insert(&my_list, my_getnbr(av[i]));
    }
    //rra(&my_list);
    //sa(&my_list);
    //ra(&my_list);
    pb(&my_seclist, &my_list);
    pb(&my_seclist, &my_list);
    pb(&my_seclist, &my_list);
    pb(&my_seclist, &my_list);
    sb(&my_seclist);
    print_list(my_list);
    print_blist(my_seclist, my_list);
    delete_b(my_seclist);
    delete(my_list);
    return (0);
}