/*
** EPITECH PROJECT, 2021
** main by Timothy CONIEL
** File description:
** main.c
*/
#include "../include/my.h"

int exit_shell(my_struct_t *info, char **env)
{
    if (my_strncmp(info->str, "exit") == 0) {
        exit(0);
    }
    return (0);
}

int act_pwd(my_struct_t *info, char **env)
{
    int x = 0;
    int t = 0;

    if (info->str[0] == 'p' && info->str[1] == 'w' && info->str[2] == 'd') {
        for (int i = 0; env[i] != 0; i++)
            if (my_strncmp(env[i], "PWD=") == 0)
                x = i;
        info->pwd = malloc(sizeof(char) * my_strlen(env[x]));
        for (int c = 4; env[x][c] != '\0'; c++, t++)
            info->pwd[t] = env[x][c];
        info->pwd[t] = '\0';
        my_printf("%s\n", info->pwd);
        return (1);
    } else
        return (-1);
    return (0);
}

int envi(my_struct_t *info, char **env)
{
    return (0);
}

int ptr_arr(my_struct_t *info, char **env)
{
    int (*function[3])(my_struct_t *, char **) = {cd, envi, exit_shell};
    char *loul[4] = {"cd", "env", "exit", 0};
    char *str = malloc(sizeof(char) * (my_strlen(info->cmd[0]) + 1));
    int p = 0;

    for (;info->cmd[0][p + 1] != ' ' && info->cmd[0][p + 1] != '\0'; p++) {
        str[p] = info->cmd[0][p + 1];
    }
    str[p] = '\0';
    for (int i = 0; loul[i] != 0; i++) {
        if (my_strncmp(loul[i], str) == 0) {
            (*function[i]) (info, env);
            return (1);
        }
    }
    return (0);
}

int user_input(my_struct_t *info, char **env)
{
    int x = 0;
    int y = 0;
    int v = 0;
    int p = 0;
    size_t len = 0;

    while (1) {
        len = 0;
        info->str = NULL;
        my_printf("$>");
        if (getline(&info->str, &len, stdin) != -1) {
            info->str = keep_alpha(info);
            my_count_word(info);
            p = ptr_arr(info, env);
            if (p != 1) {
                y = shell(info);
                if (y == -2)
                    return (84);
            }
        } else
            return (0);
    }
    exit(info->process_id1);
    return (0);
}

int find_path(char **env, my_struct_t *info)
{
    int x = 0;
    int t = 0;
    int f = 0;

    for (int i = 0; env[i] != 0; i++)
        if (my_strncmp(env[i], "PATH=") == 0)
            x = i;
    info->bin_path = malloc(sizeof(char *) * my_strlen(env[x]));
    info->bin_path[t] = malloc(sizeof(char) * 100);
    for (int y = 5; env[x][y] != '\0'; y++) {
        if (env[x][y] == ':' || env[x][y] == '\n') {
            info->bin_path[t][f] = '\0';
            f = 0;
            t++;
            info->bin_path[t] = malloc(sizeof(char) * 100);
        } else {
            info->bin_path[t][f] = env[x][y];
            f++;
        }
    }
    info->bin_path[t][f] = '\0';
    info->bin_path[t + 1] = NULL;
    info->cmd_nbrp = t;
    return (0);
}

int main(int ac, char **av, char **env)
{
    my_struct_t *info = malloc(sizeof(my_struct_t));

    find_path(env, info);
    //for (int i = 0; env[i] != NULL; i++)
    //    my_printf("%s\n", env[i]);
    if (info == NULL || ac > 1 || user_input(info, env) == -1)
        return (84);
    return (0);
}
