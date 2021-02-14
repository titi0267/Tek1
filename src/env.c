/*
** EPITECH PROJECT, 2021
** env by Timothy CONIEL
** File description:
** env.c
*/

#include "../include/my.h"

int search(my_struct_t *info, char **env)
{
    int i = 0;

    for (; info->new_env[i]; i++) {
        for (int p = 0; info->new_env[i][p]; p++) {
            if (info->new_env[i][p] == '=' && info->cmd[1][p] == '\0')
                return (i);
            if (info->new_env[i][p] != info->cmd[1][p])
                break;
        }
    }
    return (-1);
}

int envi(my_struct_t *info, char **env)
{
    int i = 0;

    for (; info->new_env[i] != NULL; i++) {
        for (int p = 0; info->new_env[i][p] != '\0'; p++)
            my_printf("%c", info->new_env[i][p]);
        my_printf("\n");
    }
}

int my_setenv_error(my_struct_t *info, char **env)
{
    if (info->cmd[1] == NULL) {
        envi(info, env);
        return (1);
    } else if (info->cmd[2] != NULL && info->cmd[3] != NULL) {
        my_error("setenv: Too many arguments.\n");
        return (1);
    } else if (only_alpha(info->cmd[1]) == -2) {
        my_error("setenv: Variable name must begin with a letter.\n");
        return (1);
    } else if (only_alpha(info->cmd[1]) == -1) {
        my_error("setenv: Variable name must contain alphanumeric characters.\n");
        return (1);
    }
    return (0);
}

int my_setenv(my_struct_t *info, char **env)
{
    int x = 0;

    if (my_setenv_error(info, env) != 0)
        return (1);
    if ((x = search(info, env)) == -1)
        create_env(info);
    else
        alrd_setenv(info, x);
    return (1);
}
