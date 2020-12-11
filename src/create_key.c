/*
** EPITECH PROJECT, 2020
** create_key.c by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** create_key
*/

#include "../include/my.h"
#include <stdlib.h>

int ascii(char **av, infin_number_t *info)
{
    int i = 0;
    for (info->i = 0; av[2][info->i] != '\0'; info->i++);
    info->store_key = (int *)malloc(sizeof(int *) * info->i);
    if (info->store_key == NULL)
        return (84);
    for (; av[2][i] != '\0'; i++) {
        info->store_key[i] = av[2][i];
    }
    info->store_key[i] = 0;
    return (0);
}

void print_2x0(int y, infin_number_t *info)
{
    info->fill_matrix = 0;
    for (; y < 4; y++) {
        info->fill_matrix++;
        printf("0");
        if (y == 0 || y == 2)
            printf("       ");
        if (y == 1 || y == 3) {
            printf("\n");
        }
    }
}

void print_2matrix(infin_number_t *info)
{
    int i = 1;
    int y = 0;

    for (; info->store_key[y] != 0; i++, y++) {
        printf("%i", info->store_key[y]);
        if (my_intlen(info->store_key[y]) == 2 && i == 1) {
            printf("      ");
        } else if (my_intlen(info->store_key[y]) == 3 && i == 1) {
            printf("     ");
        }
        if (i == 2) {
            printf("\n");
            i = 0;
        }
    }
    print_2x0(y, info);
}

void print_3x0(int y, infin_number_t *info)
{
    info->fill_matrix = 0;
    for (; y < 9; y++) {
        info->fill_matrix++;
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
    print_3x0(y, info);
}

int print_matrix(char **av, infin_number_t *info)
{
    ascii(av, info);
    if (ascii(av, info) == 84)
        return (84);
    printf("Key matrix:\n");
    for (info->i = 0; av[2][info->i] != '\0'; info->i++);
    if (info->i == 1) {
        printf("%i\n", info->store_key[0]);
        info->divide = 1;
    } else if (info->i >= 2 && info->i <= 4) {
        print_2matrix(info);
        info->divide = 2;
    } else if (info->i >= 5 && info->i <= 9) {
        print_3matrix(info);
        info->divide = 3;
    } else {
        printf("The encryption key is longer than 9 or less than 1 characters, it isn't supported yet\n");
        return (84);
    }
    return (0);
}