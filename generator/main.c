/*
** EPITECH PROJECT, 2020
** B-CPE-200-STG-2-1-dante-timothe.coniel
** File description:
** main.c
*/

#include "../include/my.h"
#include "include/dante.h"

int main(int ac, char **av)
{
    data_t *data = malloc(sizeof(data_t));
    int error_status = error_handler(ac, av, data);

    if (error_status == 1) return (0);
    else if (error_status == 0) {
        
    }
    else return (84);
}