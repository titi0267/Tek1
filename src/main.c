/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** 
*/

#include "../include/my.h"

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
    for (int i = 0; duo->line[i] != NULL; i++) {
        for (int t = 0; duo->line[i][t] != '\0'; t++)
            printf("%c", duo->line[i][t]);
        printf("\n");
    }
    free_func(duo);
    return (0);
}
