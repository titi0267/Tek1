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
    int f = 0;

    carac_on_line(buff, info);
    for (; buff[i] != '\0'; i++) {
        if (buff[i] == '\n')
            o++;
    }
    for (i = info->nbr; buff[i] != '\0'; i++) {
        if (buff[i] != '.' && buff[i] != 'o' && buff[i] != '\n')
            return (84);
        if (i < (my_strlen(buff) - info->carac_l) && buff[i] == '\n' && buff[i + info->carac_l] == '\n')
            f++;
    }
    return ((o - 1 == x && f + 1 == x) ? 1 : 84);
}

