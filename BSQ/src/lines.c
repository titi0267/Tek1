/*
** EPITECH PROinfo->jECT, 2020
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

void square(char *buff, buffer_size_t *info)
{
    carac_on_line(buff, info);
    int i = info->nbr;

    for (; buff[i] != '\0'; i++) {
        if (buff[i] == '.') {
            info->j[i] = 1;
        }
        if (buff[i] == 'o') {
            info->j[i] = 0;
        }
        if (buff[i] == '\n') {
            info->j[i] = -1;
       }
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

void size_square(int i, buffer_size_t *info)
{
    int x = 0;

    if (i > info->carac_l && info->j[i - 1] >= info->j[i] &&
        info->j[i - info->carac_l] >= info->j[i]
        && info->j[i - info->carac_l - 1] >= info->j[i]) {
        x = biggest(i, info);
        if (x == 1)
            info->j[i] = info->j[i - info->carac_l] + info->j[i];
        if (x == 2)
            info->j[i] = info->j[i - 1] + info->j[i];
        if (x == 3)
            info->j[i] = info->j[i - info->carac_l - 1] + info->j[i];
        else if (x == 0)
            info->j[i] = info->j[i];
    }
}