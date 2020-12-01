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

int main(int ac, char **av)
{
    struct list_t *my_list;
    int x = error(ac, av);

    my_list = NULL;
    if (x != 0)
        return (84);
    for (int i = 1; av[i] != 0; i++) {
        insert(&my_list, my_getnbr(av[i]));
    }

    print_list(my_list);
    delete(my_list);
    return 0;
}