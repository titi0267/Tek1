/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main.c
*/

#include "../include/my.h"

static void size(duo_stp_t *duo, char **av, int ac)
{
    if (ac == 5)
        duo->size = my_getnbr(av[4]);
    else
        duo->size = 8;
    for (int i = 0; i < (duo->size + 2); i++)
        printf("+");
    printf("\n");
}

static void free_func(duo_stp_t *duo)
{
    free(duo->buffer);
    free(duo);
}

int main(int ac, char **av)
{
    duo_stp_t *duo = malloc(sizeof(duo_stp_t));

    if (duo == NULL)
        return (84);
    if (read_map(duo, av) == 84)
        return (84);
    if (store_words(duo) == 84)
        return (84);
    size(duo, av, ac);
    for (int i = 0; duo->line[i] != NULL; i++) {
        printf("|");
        for (int t = 0; duo->line[i][t] != '\0'; t++)
            printf("%c", duo->line[i][t]);
        printf("|");
        printf("\n");
    }
    size(duo, av, ac);
    free_func(duo);
    return (0);
}
