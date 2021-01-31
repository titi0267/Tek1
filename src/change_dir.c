/*
** EPITECH PROJECT, 2021
** change directory by Timothy CONIEL
** File description:
** change_dir.c
*/

#include "../include/my.h"

int cd(my_struct_t *info, char **env)
{
    int p = 0;
    int y = 0;
    int x = 0;

    for (x = 2; info->str[x] != '\0'; x++, p++);
    info->cd_pwd = malloc(sizeof(char) * p + 1);
    for (int m = 3; y != p - 1; m++, y++) {
        info->cd_pwd[y] = info->str[m];
    }
    info->cd_pwd[y] = '\0';
    if (chdir(info->cd_pwd) != 0) {
        my_error(info->cd_pwd);
        my_error(": No such file or directory.\n");
    }
    return (0);
}
