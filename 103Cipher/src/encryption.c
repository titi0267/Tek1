/*
** EPITECH PROJECT, 2020
** encryption.c by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** encryption
*/

#include <stdlib.h>
#include "../include/my.h"

int store_sentence(char **av, infin_number_t *info)
{
    int i = 0;
    int x = 0;

    for (info->strlen = 0; av[1][info->strlen] != 0; info->strlen++);
    info->sentence = malloc(sizeof(int) * info->strlen);
    if (info->sentence == NULL)
        return (84);
    for (; i < info->strlen; i++) {
        info->sentence[i] = av[1][i];
    }
    while (i > info->divide) {
        i = i - info->divide;
    }
    for (; i < info->divide; i++)
        x++;
    info->fill_sentence = x;
    while (x > 0) {
        info->sentence[info->strlen + x] = 0;
        x--;
}
    return (0);
}

int encrypt_3(char **av, infin_number_t *info)
{
    int x = 0;

    store_sentence(av, info);
    info->encrypt = malloc(sizeof(int) * info->strlen);
    if (info->encrypt == NULL || store_sentence(av, info) == 84)
        return (84);
    for (int i = 0; i < (info->strlen + info->fill_sentence); i++, x++) {
        if (x == 0) {
            info->encrypt[i] = (info->sentence[i] * info->store_key[0]) + (info->sentence[i + 1] * info->store_key[3]) + (info->sentence[i + 2] * info->store_key[6]);
        }
        if (x == 1) {
            info->encrypt[i] = (info->sentence[i - 1] * info->store_key[1]) + (info->sentence[i] * info->store_key[4]) + (info->sentence[i + 1] * info->store_key[7]);
        }
        if (x == 2) {
            info->encrypt[i] = (info->sentence[i - 2] * info->store_key[2]) + (info->sentence[i - 1] * info->store_key[5]) + (info->sentence[i] * info->store_key[8]);
            x = -1;
        }
        if (i < (info->strlen + info->fill_sentence - 1)) {
            my_printf("%i ", info->encrypt[i]);
        }
        else
            my_printf("%i", info->encrypt[i]);
    }
    free(info->encrypt);
    return (0);
}

int encrypt_2(char **av, infin_number_t *info)
{
    int x = 0;

    store_sentence(av, info);
    info->encrypt = malloc(sizeof(int) * info->strlen);
    if (info->encrypt == NULL || store_sentence(av, info) == 84)
        return (84);
    for (int i = 0; i < (info->strlen + info->fill_sentence); i++, x++) {
        if (x == 0) {
            info->encrypt[i] = (info->sentence[i] * info->store_key[0]) + (info->sentence[i + 1] * info->store_key[2]);
        }
        if (x == 1) {
            info->encrypt[i] = (info->sentence[i - 1] * info->store_key[1]) + (info->sentence[i] * info->store_key[3]);
            x = -1;
        } if (i < (info->strlen + info->fill_sentence - 1))
            printf("%i ", info->encrypt[i]);
        else
            printf("%i\n", info->encrypt[i]);
    }
    free(info->encrypt);
    return (0);
}


int encrypt_1(char **av, infin_number_t *info)
{
    store_sentence(av, info);
    info->encrypt = malloc(sizeof(int) * info->strlen);
    if (info->encrypt == NULL || store_sentence(av, info) == 84)
        return (84);
    for (int i = 0; i < info->strlen; i++) {
            info->encrypt[i] = (info->sentence[i] * info->store_key[0]);
        if (i < (info->strlen - 1))
            printf("%i ", info->encrypt[i]);
        else
            printf("%i\n", info->encrypt[i]);
    }
    free(info->encrypt);
    return (0);
}