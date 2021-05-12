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
    char *str = NULL;

    if (check_error(ac) != 0)
        return (84);
    ai(str);
    return (0);
}