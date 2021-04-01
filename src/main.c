/*
** EPITECH PROJECT, 2021
** main
** File description:
** main for duo
*/

#include "../include/my.h"

int find_arg(char **av)
{
    for (int i = 0; av[i] != NULL; i++) {
        for (int g = 0; av[i][g] != '\0'; g++) {
            if (i == 1 && av[i][g] == '-'
                && av[i][g + 1] == 'n')
                return (i);
        }
    }
    return (0);
}

int store_nbrs(char **av, duo_stp_t *duo)
{
    int y = 0;
    int x = find_arg(av);
    int i = 0;
    duo->nbrs = malloc(sizeof(char *) * (my_strlen(av[x + 1]) + 1));

    if (duo->nbrs == NULL)
        return (84);
    for (; av[x + 1][i] != '\0'; i++) {
        duo->nbrs[i] = malloc(sizeof(char) * 2);
        if (duo->nbrs[i] == NULL)
            return (84);
        duo->nbrs[i][y] = av[x + 1][i];
        y++;
        duo->nbrs[i][y] = '\0';
        y = 0;
    }
    duo->nbrs[i] = NULL;
    duo->len = i;
    return (0);
}

void free_func(duo_stp_t *duo)
{
    for (int i = 0; duo->nbrs[i] != NULL; i++)
        free(duo->nbrs[i]);
    free(duo->nbrs);
    free(duo);
}

int main(int ac, char **av)
{
    duo_stp_t *duo = malloc(sizeof(duo_stp_t));

    if (duo == NULL || store_nbrs(av, duo) == 84)
        return (84);
    open_file(duo);
    print_digit(duo);
    free_func(duo);
    return (0);
}
