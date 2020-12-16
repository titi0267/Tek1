/*
** EPITECH PROJECT, 2020
** connection.c by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** connection
*/

#include "../include/my.h"
#include "../include/my_struct.h"
#include <stdlib.h>
#include <stdio.h>

int which_player(char *player)
{
    for (int i = 0; )
}

int connection(int ac, char **av, infin_number_t *info)
{
    for (int i = 1; av[i] != 0; i++) {
        if (which_player(av[i]) == 1) {
            display_pid(info);
        }
    }
}