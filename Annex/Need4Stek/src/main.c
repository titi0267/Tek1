/*
** EPITECH PROJECT, 2021
** main.c for n4s project by Maxime HOFFBECK, Timothy CONIEL & Elliot WALDVOGEL
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

int main(int ac, char **av)
{
    nfors_t *nfs = malloc(sizeof(nfors_t));

    if (check_error(ac) != 0)
        return (84);
    nfs->avoiding = 0;
    nfs->avoid_mul = 0;
    nfs->stop = 0;
    nfs->wheel = 0;
    nfs->end_car = 0;
    ai(nfs);
    return (0);
}