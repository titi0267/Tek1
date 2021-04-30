/*
** EPITECH PROJECT, 2021
** user input by Timothy CONIEL
** File description:
** recover user input
*/

#include "../include/my.h"

static void compare_strings(stumper_t *stp)
{
    if (my_strcmp())
        return (0);
}

static int input_core(stumper_t *stp)
{
    compare_strings(stp);
    printf("Tries: %i\n", stp->tries);
    return (0);
}

int get_usr_line(stumper_t *stp)
{
    size_t len = 0;

    while (1) {
        len = 0;
        stp->str = NULL;
        printf("Your letter: ");
        if (getline(&stp->str, &len, stdin) != -1) {
            input_core(stp);
            printf("%s", stp->str);
        } else
            return (2);
    }
    return (0);
}
