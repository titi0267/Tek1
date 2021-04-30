/*
** EPITECH PROJECT, 2021
** B-CPE-210-STG-2-1-stumper5-tom.nomine
** File description:
** main
*/

#include "my.h"
#include <stdlib.h>
#include <stddef.h>

static void free_all(stumper_t *stp)
{
    free(stp->buffer);
    for (int i = 0; stp->line[i] != NULL; i++)
        free(stp->line[i]);
    free(stp->line);
    free(stp->star);
}

static int word_in_star(stumper_t *stp)
{
    int i = my_strlen(stp->line[stp->word]);
    int d = 0;

    if ((stp->star = malloc(sizeof(char) * i)) == NULL)
        return (84);
    for (; stp->line[stp->word][d] != '\n'; d++) {
        stp->star[d] = '*';
    }
    stp->star[d] = '\0';
    printf("%s\nTries: %i\n\n", stp->star, stp->tries);
    return (0);
    
}

static void choose_word(int ac, char **av,  stumper_t *stp)
{
    if (ac == 4) {
        stp->word = my_getnbr(av[3]) - 1;
        stp->tries = my_getnbr(av[2]);
        return;
    } else {
        srand(time(NULL));
        stp->word = rand() % stp->line_nbr;
        stp->tries = 10;
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
    if (word_in_star(stp) == 84)
        return (84);
    get_usr_line(stp);
    free_all(stp);
    free(stp);
    return (0);
}
