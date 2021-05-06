/*
** EPITECH PROJECT, 2021
** B-CPE-210-STG-2-1-stumper5-tom.nomine
** File description:
** base
*/

#include "my.h"

static int init_temp_values(stumper_t *stp)
{
    int i = 0;

    stp->str = malloc(sizeof(char) * my_strlen(av[1]) + 1);
    stp->new_str = malloc(sizeof(char) * my_strlen(av[1]) + 1);

    for (; av[1][i] != '\0'; i++) {
        stp->str[i] = av[1][i];
    }
    stp->str[i] = '\0';
}

static int compare_str_next(stumper_t *stp, int i, int d)
{
    if (stp->str[i] == av[1][d]) {
        stp->occurence++;
    }
}

static void change_str(stumper_t *stp, int i)
{
    int s = 0;
    int f = 0;

    for (int d = 0; stp->str[d] != '\0'; d++) {
        if (stp->str[i] == stp->str[d])
            d++;
        else {
            stp->new_str[s] = stp->str[d];
            s++;
        }
    }
    stp->new_str[s] = '\0';
    for (; stp->new_str[f] != '\0'; f++)
        stp->str[f] = stp->new_str[f];
    stp->str[f] = '\0';
}

static void compare_strings(stumper_t *stp, char **av)
{
    for (int i = 0; stp->str[i] != '\0'; i++) {
        for (int d = 0; av[1][d] != '\0'; d++) {
            compare_str_next(stp, i, d);
        }
        printf("%c:%i\n", stp->str[i], stp->occurence);
        change_str(stp, i);
        stp->occurence = 0;
    }
}

int main(int ac, char **av)
{
    stumper_t *stp = malloc(sizeof(stupmer_t));

    init_temp_values(stp, av);
    compare_strings(stp, av);
    if (stp == NULL)
        return (84);
    free(stp);
    return (0);
}
