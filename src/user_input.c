/*
** EPITECH PROJECT, 2021
** user input by Timothy CONIEL
** File description:
** recover user input
*/

#include "../include/my.h"

static int input_core(stumper_t *stp)
{
    
    return (0);
}

int get_usr_line(stumper_t *stp)
{
    size_t len = 0;

    while (1) {
        len = 0;
        stp->str = NULL;
        if (getline(&stp->str, &len, stdin) != -1) {
            input_core(stp);
            printf("recup user : %s", stp->str);
        } else
            return (2);
    }
    return (0);
}
