/*
** EPITECH PROJECT, 2021
** unsetenv by Timothy CONIEL
** File description:
** unsetenv.c
*/

#include "../include/my.h"

int *prepare_un(my_struct_t *info)
{
    int *x = malloc(sizeof(int) * 2);

    if (info->cmd[1] == NULL) {
        my_error("unsetenv: Too few arguments.\n");
        x[0] = -1;
        return (x);
    }
    x = search_toun(info);
    store_unenv(info);
    return (x);
}

void remove_env(my_struct_t *info, int i, int m)
{
    int p = 0;

    info->rm_env[m] = malloc(sizeof(char) * (my_strlen(info->new_env[i]) + 1));
    for (; info->new_env[i][p] != '\0'; p++) {
        info->rm_env[m][p] = info->new_env[i][p];
    }
    info->rm_env[m][p] = '\0';
}

void skip_env(my_struct_t *info, int *x, int y, int g)
{
    int i = 0;
    int m = 0;

    for (; info->new_env[i] != 0; i++, m++) {
        for (int d = 0; x[d] != -1; d++) {
            if (i == x[d] && (y - 1) != x[d]) {
                m--;
                break;
            }
            if ((y - 1) == x[d] && i == x[d]) {
                g = 1;
                break;
            }
            remove_env(info, i, m);
        }
        if (g == 1)
            break;
    }
    info->rm_env[m] = NULL;
}

int my_unsetenv(my_struct_t *info, char **env)
{
    int *x;
    int y = 0;
    int g = 0;

    x = prepare_un(info);
    if (x[0] == -1)
        return (-1);
    else {
        for (; info->new_env[y] != 0; y++);
        info->rm_env = malloc(sizeof(char *) * y);
        skip_env(info, x, y, g);
        g = 0;
    }
    info->new_env = info->rm_env;
    return (0);
}

int alrdy_unenv(my_struct_t *info, char **env)
{
    if (my_unsetenv(info, env) == -1) {
        return (0);
    }
}
