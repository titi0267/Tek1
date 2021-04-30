/*
** EPITECH PROJECT, 2021
** B-CPE-210-STG-2-1-stumper5-tom.nomine
** File description:
** main
*/

#include "my.h"
#include <stdlib.h>
#include <stddef.h>

int main(int ac, char **av)
{
    stumper_t *stp = malloc(sizeof(stumper_t));

    if (stp == NULL || error_core(ac, av, stp) == 84)
        return (84);
    read_map(stp, av);
    store_map(stp);
    for (int i = 0; stp->line[i] != NULL; i++) {
        for (int c = 0; stp->line[i][c] != '\0'; c++)
            printf("%c", stp->line[i][c]);
    }
    return (0);
}
