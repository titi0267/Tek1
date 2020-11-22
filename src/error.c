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

    carac_on_line(buff, info);
    for (; buff[i] != '\0'; i++) {
        if (buff[i] == '\n')
            o++;
    }
    for (i = info->nbr; buff[i] != '\0'; i++) {
        if (buff[i] != '.' && buff[i] != 'o' && buff[i] != '\n')
            return (84);
    }
    if (o - 1 == x)
        return (1);
    else
        return (84);
    return (0);
}

