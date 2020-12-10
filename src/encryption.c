/*
** EPITECH PROJECT, 2020
** encryption.c by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** encryption
*/
#include <stdlib.h>
#include "../include/my.h"

void store_sentence(char **av, infin_number_t *info)
{
    for (info->strlen = 0; av[1][info->strlen] != 0; info->strlen++);
    info->sentence = (int *)malloc(sizeof(int *) * info->strlen);
    for (int i = 0; i < info->strlen; i++) {
        info->sentence[i] = av[1][i];
    }
}

int encrypt_3(char **av, infin_number_t *info)
{
    int x = 0;

    store_sentence(av, info);
    info->encrypt = (int *)malloc(sizeof(int *) * info->strlen);
    for (int i = 0; (i + info->fill_matrix - 1) <= (info->strlen + info->fill_matrix); i++, x++) {
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
        if ((i + info->fill_matrix - 1) < (info->strlen + info->fill_matrix))
            printf("%i ", info->encrypt[i]);
        else
            printf("%i\n", info->encrypt[i]);
    }
    return (0);
}