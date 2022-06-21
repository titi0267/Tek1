/*
** EPITECH PROJECT, 2021
** error_handling.c for n4s project by Maxime HOFFBECK, Timothy CONIEL & Elliot WALDVOGEL
** File description:
** error_handling
*/

#include "../include/my.h"

int check_error(int ac)
{
    if (ac != 1)
        return (84);
    return (0);
}