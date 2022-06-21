/*
** EPITECH PROJECT, 2021
** main by Timothy CONIEL
** File description:
** main.c
*/
#include "../include/my.h"

int no_env(my_struct_t *info, int i, int x, char **env)
{
    int t = 0;

    if (env[x] == NULL) {
        info->bin_path = malloc(sizeof(char *) * 1);
        info->bin_path[t] = malloc(sizeof(char) * 9);
        info->bin_path[i] = NULL;
        info->cmd_nbrp = t;
        return (0);
    }
    info->bin_path = malloc(sizeof(char *) * my_strlen(env[x]));
    info->bin_path[t] = malloc(sizeof(char) * 1000);
    return (1);
}

void store_path(my_struct_t *info, int x, char **env)
{
    int t = 0;
    int f = 0;

    for (int y = 5; env[x][y] != '\0'; y++) {
        if (env[x][y] == ':' || env[x][y] == '\n') {
            info->bin_path[t][f] = '\0';
            f = 0;
            t++;
            info->bin_path[t] = malloc(sizeof(char) * 1000);
        } else {
            info->bin_path[t][f] = env[x][y];
            f++;
        }
    }
    info->bin_path[t][f] = '\0';
    info->bin_path[t + 1] = NULL;
    info->cmd_nbrp = t;
}

int find_path(char **env, my_struct_t *info)
{
    int x = 0;
    int i = 0;

    for (; env[i] != 0; i++) {
        if (my_strncmp(env[i], "PATH=") == 0)
            x = i;
    }
    if (no_env(info, i, x, env) == 0)
        return (0);
    store_path(info, x, env);
    return (0);
}

int main(int ac, char **av, char **env)
{
    my_struct_t *info = malloc(sizeof(my_struct_t));

    store_env(info, env);
    find_path(env, info);
    if (info == NULL || ac > 1 || user_input(info, env) == -1)
        return (84);
    return (0);
}
