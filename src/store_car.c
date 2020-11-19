/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-BSQ-timothe.coniel
** File description:
** store_car
*/
#include "../include/my.h"
#include "../include/steps.h"

void carac_on_line(char *buff, buffer_size_t *info)
{
    int nbr = 0;
    info->carac_l = 0;
    int line_char = 0;
    int carac = 1;
    info->arr_max = 0;

    for (; buff[nbr] >= 48 && buff[nbr] <= 57; nbr++);
    nbr = nbr + 1;
    for (line_char = nbr; buff[line_char] != '\n'; line_char++)
        carac++;
    info->carac_l = carac;
    for (; buff[info->arr_max] != '\0'; info->arr_max++);
}

void biggest(char *buff, int i, buffer_size_t *info)
{
    if (buff[i - info->carac_l] >= buff[i - info->carac_l - 1] && buff[i - info->carac_l] >=  buff[i - 1])
        buff[i] = buff[i] + buff[i - info->carac_l];
    if (buff[i - info->carac_l - 1] >= buff[i - info->carac_l] && buff[i - info->carac_l - 1] >=  buff[i - 1])
        buff[i] = buff[i] + buff[i - info->carac_l - 1];
    if (buff[i - 1] >= buff[i - info->carac_l - 1] && buff[i - 1] >=  buff[i - info->carac_l])
        buff[i] = buff[i] + buff[i - 1];
}
void square(char *buff, buffer_size_t *info)
{
    carac_on_line(buff, info);
    int i = 0;
    for (; buff[i] != '\0'; i++) {
        if (buff[i] == '.') {
            buff[i] = 1;
            my_put_nbr(1);
        }
        if (buff[i] == 'o') {
            buff[i] = 0;
            my_put_nbr(0);
        }
        if (buff[i] == '\n') {
            buff[i] = 0;
            my_putchar('\n');
        }
    }
}

void calc(char *buff, buffer_size_t *info)
{
    square(buff, info);
    int i = 0;
    for (; buff[i] != '\0'; i++) {
        if (buff[i] == 1)
            if (buff[i - info->carac_l] < buff[i] || buff[i - info->carac_l - 1] < buff[i] || buff[i - 1] < buff[i])
                buff[i] = buff[i];
            else if (buff[i - info->carac_l] >= buff[i] && buff[i - info->carac_l - 1] >= buff[i] && buff[i - 1] >= buff[i])
                biggest(buff, i, info);
    }
}
