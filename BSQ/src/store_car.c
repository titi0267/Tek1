/*
** EPITECH PROinfo->jECT, 2020
** B-CPE-110-STG-1-1-BSQ-timothe.coniel
** File description:
** store_car
*/
#include "../include/my.h"
#include "../include/steps.h"

int biggest(int i, buffer_size_t *info)
{
    if (i > info->carac_l && info->j[i - info->carac_l] <= info->j[i - 1] &&
            info->j[i - info->carac_l] <= info->j[i - info->carac_l - 1])
        return (1);
    else if (i > info->carac_l &&
            info->j[i - 1] <= info->j[i - info->carac_l] &&
            info->j[i - 1] <= info->j[i - info->carac_l - 1])
        return (2);
    else if (i > info->carac_l &&
            info->j[i - info->carac_l - 1] <= info->j[i - 1] &&
            info->j[i - info->carac_l - 1] <= info->j[i - info->carac_l])
        return (3);
    return (0);
}

void calc(char *buff, buffer_size_t *info)
{
    int i = 0;

    carac_on_line(buff, info);
    square(buff, info);
    for (; buff[i] != '\0'; i++) {
        if (info->j[i] == 1 && i > info->carac_l)
            size_square(i, info);
    }
}

void find_square(char *buff, buffer_size_t *info)
{
    int i = 0;

    calc(buff, info);
    info->big = 0;
    info->where = 0;
    for (; buff[i] != '\0'; i++) {
        if (info->j[i] > info->big) {
            info->big = info->j[i];
            info->where = i;
        }
    }
}

void initial_square(char *buff, buffer_size_t *info)
{
    find_square(buff, info);
    int i = info->nbr;

    for (; buff[i] != '\0'; i++) {
        if (info->j[i] == 0)
            buff[i] = 'o';
        else if (info->j[i] == -1)
            buff[i] = '\n';
        else if (info->j[i] == 1)
            buff[i] = '.';
        if (i == info->where) {
            replace(buff, i, info);
        }
    }
}