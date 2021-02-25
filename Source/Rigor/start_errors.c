/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** start_errors
*/

#include "../../include/defender.h"

int start_error(int ac, char **av)
{
    if (ac != 1) {
        my_puterr("This program needs one argument only !\n");
        return (ERROR);
    }
    return (0);
}