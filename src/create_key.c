/*
** EPITECH PROJECT, 2020
** create_key.c by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** create_key
*/

#include "../include/my.h"
#include <stdlib.h>

void ascii(char **av, infin_number_t *info)
{
    int i = 0;
    for (info->i = 0; av[2][info->i] != '\0'; info->i++);
    info->store_key = (int *)malloc(sizeof(int *) * info->i);
    for (; av[2][i] != '\0'; i++) {
        info->store_key[i] = av[2][i];
    }
    info->store_key[i] = 0;
}

int print_matrix(char **av, infin_number_t *info)
{
    ascii(av, info);
    printf("Key matrix:\n");
    if (info->i == 1) {
        printf("%i\n", info->store_key[0]);
        printf("Print a 1 by 1 matrix");
    }
    else if (info->i >= 2 && info->i <= 4) {
        print_2matrix(info);
        printf("Print a 2 by 2 matrix");
    }
    else if (info->i >= 5 && info->i <= 9) {
        //print_3matrix();
        printf("Print a 3 by 3 matrix");
    }
    else {
        printf("The encryption key is longer than 9 characters, it isn't supported yet\n");
        return (84);
    }
    return (0);
}

void print_2matrix(infin_number_t *info)
{
    int i = 0;
    int x = 0;
    int y = 0;
    for (; info->store_key[y] != 0; i++, y++) {
        printf("%i", info->store_key[y]);
        if (i < 1)
        if (my(strlen(info->store_key[y]) == 2))
            printf("      ");
        else if (my_strlen(info->store_key[y]) == 3)
            printf("     ");
        if (i == 1) {
        printf("\n");
        i = 0;
        }
        x = i;
    }
    if (y < 4) {
        for (;y < 4; x++, y++) {
            printf("0");
            if (x < 1)
                printf("    ");
            if (x == 1) {
                printf("\n");
                x = 0;
            }
        }
    }
}