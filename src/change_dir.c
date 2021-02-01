/*
** EPITECH PROJECT, 2021
** change directory by Timothy CONIEL
** File description:
** change_dir.c
*/

#include "../include/my.h"

int cd_arg(my_struct_t *info)
{
    int i = 0;
    int x = 0;
    int c = 0;

    for (; info->new_env[i] != 0; i++) {
        if (my_strncmp(info->new_env[i], "HOME=") == 0)
            x = i;
    }
    for (int p = 5; info->new_env[x][p] != '\0'; p++, c++)
        info->cd_pwd[c] = info->new_env[x][p];
    info->cd_pwd[c] = '\0';
}

int cd(my_struct_t *info, char **env)
{
    int p = 0;
    int y = 0;
    int x = 0;

    for (x = 2; info->str[x] != '\0'; x++, p++);
    info->cd_pwd = malloc(sizeof(char) * p + 1);
    if (info->cmd[1] == NULL) {
        cd_arg(info);
        if (chdir(info->cd_pwd) != 0) {
            my_error(info->cd_pwd);
            my_error(": No such file or directory.\n");
        }
        return (0);
    }
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
