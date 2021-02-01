/*
** EPITECH PROJECT, 2021
** builtin command by Timothy CONIEL
** File description:
** builtin_cmd.c
*/

#include "../include/my.h"

int ptr_arr(my_struct_t *info, char **env)
{
    int (*function[5])(my_struct_t *, char **) = {cd, envi, exit_shell,
    my_setenv, my_unsetenv};
    char *loul[6] = {"cd", "env", "exit", "setenv", "unsetenv", 0};
    int p = 0;

    if (info->str[0] == '\0')
        return (-1);
    char *str = malloc(sizeof(char) * (my_strlen(info->cmd[0]) + 1));
    for (;info->cmd[0][p + 1] != ' ' && info->cmd[0][p + 1] != '\0'; p++) {
        str[p] = info->cmd[0][p + 1];
    }
    str[p] = '\0';
    for (int i = 0; loul[i] != 0; i++) {
        if (my_strxcmp(loul[i], str) == 0) {
            (*function[i]) (info, env);
            return (1);
        }
    }
    return (0);
}

int exit_shell(my_struct_t *info, char **env)
{
    if (info->cmd[1] != NULL) {
        exit(my_getnbr(info->cmd[1]));
    } else
        exit(0);
    return (0);
}