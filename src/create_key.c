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

void print_2x0(int y, int x)
{
    for (; y < 4; y++, x++) {
        printf("0");
        if (x == 0)
            printf("       ");
        if (x == 1) {
            printf("\n");
            x = 0;
        }
    }
}

void print_2matrix(infin_number_t *info)
{
    int i = 1;
    int x = 0;
    int y = 0;

    for (; info->store_key[y] != 0; i++, y++) {
        printf("%i", info->store_key[y]);
        if (my_intlen(info->store_key[y]) == 2 && i == 1) {
            printf("      ");
            x = 1;
        } else if (my_intlen(info->store_key[y]) == 3 && i == 1) {
            printf("     ");
            x = 1;
        }
        if (i == 2) {
            printf("\n");
            i = 0;
            x = 0;
        }
    }
    print_2x0(y, x);
}

void print_3x0(int y)
{
    for (; y < 9; y++) {
        printf("0");
        if (y != 5 && y != 8 && y != 2)
            printf("       ");
        else {
            printf("\n");
        }
    }
}

void print_3matrix(infin_number_t *info)
{
    int i = 1;
    int y = 0;

    for (; info->store_key[y] != 0; y++, i++) {
        printf("%i", info->store_key[y]);
        if (my_intlen(info->store_key[y]) == 2 && (i == 1 || i == 2))
            printf("      ");
        else if (my_intlen(info->store_key[y]) == 3 && (i == 1 || i == 2))
            printf("     ");
        if (i == 3) {
            printf("\n");
            i = 0;
        }
    }
    print_3x0(y);
}

int print_matrix(char **av, infin_number_t *info)
{
    ascii(av, info);
    printf("Key matrix:\n");
    for (info->i = 0; av[2][info->i] != '\0'; info->i++);
    if (info->i == 1)
        printf("%i\n", info->store_key[0]);
    else if (info->i >= 2 && info->i <= 4)
        print_2matrix(info);
    else if (info->i >= 5 && info->i <= 9)
        print_3matrix(info);
    else {
        printf("The encryption key is longer than 9 characters, it isn't supported yet\n");
        return (84);
    }
    return (0);
}