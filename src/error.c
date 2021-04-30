/*
** EPITECH PROJECT, 2021
** B-CPE-210-STG-2-1-stumper5-tom.nomine
** File description:
** error
*/

#include "../include/my.h"
#include <stdlib.h>

static int error_argnbr(int ac)
{
    if (ac < 2) {
        write(2, "missing arguments", 19);
        return (84);
    } else if (ac > 4) {
        write(2, "too much arguments\n", 20);
        return (84);
    }
    return (0);
}

int error_core(int ac)
{
    if (error_argnbr(ac) == 84)
        return (84);
    return (0);
}
