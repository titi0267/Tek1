/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-BSQ-timothe.coniel
** File description:
** lines
*/

#include "../include/my.h"
#include "../include/steps.h"

void carac_on_line(char *buff, buffer_size_t *info)
{
    info->carac_l = 0;
    info->nbr = 0;
    int line_char = 0;
    int carac = 1;

    for (; buff[info->nbr] >= 48 && buff[info->nbr] <= 57; info->nbr++);
    info->nbr = info->nbr + 1;
    for (line_char = info->nbr; buff[line_char] != '\n'; line_char++)
        carac++;
    info->carac_l = carac;
}

void square(char *buff)
{
    int i = 0;

    for (; buff[i] != '\0'; i++) {
        if (buff[i] == '.')
            buff[i] = '1';
        if (buff[i] == 'o')
            buff[i] = '0';
        if (buff[i] == '\n')
            buff[i] = '\n';
    }
}

void replace(char *buff, int i, buffer_size_t *info)
{
    int x = 0;
    int m = 0;
    int t = 0;
    int v = 0;

    for (; x < info->big; x++)
        buff[i - x] = 'x';
    for (m = 0; m < info->big; m++) {
        v = i - info->carac_l * m;
        for (t = 0; t < info->big; t++)
            buff[v - t] = 'x';
    }
}

void size_square(char *buff, int i, int f, buffer_size_t *info)
{
    int x = 0;

    if (buff[i - 1] - '0' >= buff[i] - '0' &&
        buff[i - info->carac_l] - '0' >= buff[i] - '0'
        && buff[i - info->carac_l - 1] - '0' >= buff[i] - '0') {
        x = biggest(buff, i, info);
        if (x == 1) {
            f = buff[i - info->carac_l] - 48 + buff[i] - 48;
            buff[i] = f + 48;
        } if (x == 2) {
            f = buff[i - 1] - 48 + buff[i] - 48;
            buff[i] = f + 48;
        } if (x == 3) {
            f = buff[i - info->carac_l - 1] - 48 + buff[i] - 48;
            buff[i] = f + 48;
        } else if (x == 0) {
            buff[i] = buff[i];
        }
    }
}