/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** start_errors
*/

#include "../../include/defender.h"

int start_error(int ac, char **av)
{
    if (ac != 2) {
        my_puterr("This program needs two args !\n");
        return (ERROR);
    }
    return (0);
}