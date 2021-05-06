/*
** EPITECH PROJECT, 2021
** B-CPE-210-STG-2-1-stumper5-tom.nomine
** File description:
** base
*/

#include "my.h"

static int init_temp_values(stumper_t *stp, char **av)
{
    int i = 0;

    stp->str = malloc(sizeof(char) * my_strlen(av[stp->arg]) + 1);
    stp->new_str = malloc(sizeof(char) * my_strlen(av[stp->arg]) + 1);

    for (; av[stp->arg][i] != '\0'; i++) {
        stp->str[i] = av[stp->arg][i];
    }
    stp->str[i] = '\0';
}

static int compare_str_next(stumper_t *stp, int i, int d, char **av)
{
    if (stp->str[0] == av[stp->arg_first][d]) {
        stp->occurence++;
    }
}

static char *change_str(stumper_t *stp, int i, char **av)
{
    int s = 0;
    int f = 0;

    for (int d = 0; stp->str[d] != '\0'; d++) {
        if (stp->str[0] != stp->str[d]) {
            stp->new_str[s] = stp->str[d];
            s++;
        }
    }
    stp->new_str[s] = '\0';
    for (; stp->new_str[f] != '\0'; f++) {
        stp->str[f] = stp->new_str[f];
    }
    stp->str[f] = '\0';
    stp->stop = f;
    return (stp->str);
}

static void compare_strings(stumper_t *stp, char **av)
{
    for (int i = 0; stp->stop != 0; i++) {
        for (int d = 0; av[stp->arg_first][d] != '\0'; d++) {
            compare_str_next(stp, i, d, av);
        }
        printf("%c:%i\n", stp->str[0], stp->occurence);
        stp->str = change_str(stp, i, av);
        i = 0;
        stp->occurence = 0;
    }
}

int main(int ac, char **av)
{
    stumper_t *stp = malloc(sizeof(stumper_t));

    find_str(ac, av, stp);
    stp->stop = my_strlen(av[1]);
    init_temp_values(stp, av);
    compare_strings(stp, av);
    if (stp == NULL)
        return (84);
    free(stp);
    return (0);
}
