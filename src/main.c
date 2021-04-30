/*
** EPITECH PROJECT, 2021
** B-CPE-210-STG-2-1-stumper5-tom.nomine
** File description:
** main
*/

#include "my.h"
#include <stdlib.h>
#include <stddef.h>

static void choose_word(int ac, char **av,  stumper_t *stp)
{
    if (ac == 4) {
        stp->word = my_getnbr(av[3]) - 1;
        return;
    } else {
        srand(time(NULL));
        stp->word = rand() % stp->line_nbr;
    }
}

int main(int ac, char **av)
{
    stumper_t *stp = malloc(sizeof(stumper_t));

    if (stp == NULL || error_core(ac, av, stp) == 84)
        return (84);
    read_map(stp, av);
    store_map(stp);
    choose_word(ac, av, stp);
    printf("%s", stp->line[stp->word]);
/*    for (int i = 0; stp->line[i] != NULL; i++) {
        for (int c = 0; stp->line[i][c] != '\0'; c++)
            printf("%c", stp->line[i][c]);
            }*/
    return (0);
}
