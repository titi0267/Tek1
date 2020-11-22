/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-BSQ-timothe.coniel
** File description:
** error
*/
#include "../include/my.h"
#include "../include/steps.h"

int no_nbr(char *buff, buffer_size_t *info)
{
    int i = 0;
    int x = my_getnbr(buff);
    int o = 0;
    int f = 1;

    carac_on_line(buff, info);
    for (; buff[i] != '\0'; i++) {
        if (buff[i] == '\n')
            o++;
    }
    i = info->nbr;
    for (; buff[i] != '\0'; i++) {
        if (buff[i] == '\n' && buff[i + info->carac_l] == '\n')
            f++;
    }
    if (o - 1 == x && f + 1 == o)
        return (1);
    else
        return (84);
    return (0);
}

