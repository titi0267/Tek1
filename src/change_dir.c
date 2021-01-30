/*
** EPITECH PROJECT, 2021
** change directory by Timothy CONIEL
** File description:
** change_dir.c
*/

#include "../include/my.h"

int cd(my_struct_t *info)
{
    int p = 0;
    int y = 0;
    int x = 0;

    if (info->str[0] == 'c' && info->str[1] == 'd' && info->str[2] == ' ') {
        for (x = 2; info->str[x] != '\0'; x++, p++);
        info->cd_pwd = malloc(sizeof(char) * p + 1);
        for (int m = 3; y != p - 1; m++, y++) {
            info->cd_pwd[y] = info->str[m];
        }
        info->cd_pwd[y] = '\0';
        if (chdir(info->cd_pwd) != 0)
            return (-2);
    } else
        return (-1);
    return (0);
}

/*int create_cd(my_struct_t *info)
{
    int status;
    if ((info->process_id2 = fork()) == -1) {
        perror("fork");
        return (1);
    } else if (info->process_id2 == 0) {
        if (cd(info) == -2)
            return (-1);
        return (1);
    } else
        wait(&status);
    return (0);
}*/