/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-BSQ-timothe.coniel
** File description:
** store_car
*/
#include "../include/my.h"
#include "../include/steps.h"

int biggest(char *buff, int i, buffer_size_t *info)
{
    if (buff[i - info->carac_l] - '0' <= buff[i - 1] - '0' &&
            buff[i - info->carac_l] - '0' <= buff[i - info->carac_l - 1] - '0')
        return (1);
    else if (buff[i - 1] - '0' <= buff[i - info->carac_l] - '0' &&
            buff[i - 1] - '0' <= buff[i - info->carac_l - 1] - '0')
        return (2);
    else if (buff[i - info->carac_l - 1] - '0' <= buff[i - 1] - '0' &&
            buff[i - info->carac_l - 1] - '0' <= buff[i - info->carac_l] - '0')
        return (3);
    return (0);
}

void calc(char *buff, int i, buffer_size_t *info)
{
    int f = 0;

    i = 0;
    carac_on_line(buff, info);
    square(buff);
    for (; buff[i] != '\0'; i++) {
        if (buff[i] == 1 + 48 && i > info->carac_l)
            size_square(buff, i, f, info);
    }
}

void find_square(char *buff, buffer_size_t *info)
{
    int i = 0;

    calc(buff, i, info);
    info->big = 0;
    info->where = 0;
    for (; buff[i] != '\0'; i++) {
        if (buff[i] - 48 > info->big) {
            info->big = buff[i] - 48;
            info->where = i;
        }
    }
}

void initial_square(char *buff, buffer_size_t *info)
{
    find_square(buff, info);
    int i = info->nbr;

    for (; buff[i] != '\0'; i++) {
        if (buff[i] == '0')
            buff[i] = 'o';
        else if (buff[i] == '\n')
            buff[i] = '\n';
        else if (buff[i] >= 1 + 48)
            buff[i] = '.';
        if (i == info->where) {
            replace(buff, i, info);
        }
    }
}