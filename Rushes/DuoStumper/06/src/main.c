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

    if ((stp->str = malloc(sizeof(char) * my_strlen(av[stp->arg]) + 1))
        == NULL || (stp->new_str = malloc(sizeof(char) *
        my_strlen(av[stp->arg]) + 1)) == NULL)
        exit(84);
    for (; av[stp->arg][i] != '\0'; i++) {
        stp->str[i] = av[stp->arg][i];
    }
    stp->str[i] = '\0';
    return (0);
}

static void compare_str_next(stumper_t *stp, int d, char **av)
{
    if (stp->str[0] == av[stp->arg_first][d]) {
        stp->occurence++;
    }
}

static char *change_str(stumper_t *stp)
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
    int r = 0;

    for (int i = 0; stp->stop != 0; i++) {
        for (int d = 0; av[stp->arg_first][d] != '\0'; d++)
            compare_str_next(stp, d, av);
        stp->car[r] = stp->str[0];
        stp->car_nbr[r] = stp->occurence;
        printf("%c:%i\n", stp->str[0], stp->occurence);
        stp->str = change_str(stp);
        i = 0;
        stp->occurence = 0;
        r++;
    }
    stp->car[r] = '\0';
}

int main(int ac, char **av)
{
    stumper_t *stp = malloc(sizeof(stumper_t));

    if (stp == NULL)
        return (84);
    stp->t_flag = 0;
    stp->flag_r = 0;
    error_argnbr(ac);
    find_str(ac, av, stp);
    if ((stp->car = malloc(sizeof(char) * my_strlen(av[stp->arg]) + 1)) == NULL
        || (stp->car_nbr = malloc(sizeof(int) *
                                  my_strlen(av[stp->arg]) + 4)) == NULL)
        return (84);
    stp->stop = my_strlen(av[1]);
    init_temp_values(stp, av);
    compare_strings(stp, av);
    free_all(stp);
    free(stp);
    return (0);
}
