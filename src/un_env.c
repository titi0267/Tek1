/*
** EPITECH PROJECT, 2021
** unsetenv by Timothy CONIEL
** File description:
** unsetenv.c
*/

#include "../include/my.h"

void store_unenv(my_struct_t *info)
{
    int i = 0;
    int p = 0;

    info->sec_env = malloc(sizeof(char *) * (word_tablen(info->new_env) + 1));
    for (; info->new_env[i] != NULL; i++) {
        info->sec_env[i] = malloc(sizeof(char) *
        (my_strlen(info->new_env[i]) + 1));
        for (; info->new_env[i][p]; p++) {
            info->sec_env[i][p] = info->new_env[i][p];
        }
        info->sec_env[i][p] = '\0';
        p = 0;
    }
    info->end_env = i;
    info->sec_env[i] = NULL;
}

int *search_toun(my_struct_t *info)
{
    int i = 0;
    int p = 0;
    int m = 1;
    int x = 0;
    int d = 0;
    int y = 0;
    int g = 0;
    int *found_env = malloc(sizeof(int) * (word_tablen(info->cmd) + 1));

    found_env[0] = -1;
    for (; info->cmd[m] != 0; m++) {
        for (; info->new_env[i]; i++) {
                for (int y = 0; info->cmd[m][y]; y++, p++) {
                    for (int f = 0; f <= d; f++) {
                        if (info->new_env[i][p] != info->cmd[m][y] || found_env[f] == i) {
                            g = 1;
                            break;
                        }
                    }
                    if (g == 1)
                        break;
                    if (info->new_env[i][p + 1] == '=') {
                        found_env[d] = i;
                        d++;
                        found_env[d] = -1;
                        break;
                    }
                }
                y = 0;
            p = 0;
            g = 0;
        }
        i = 0;
    }
    found_env[d] = -1;
    return (found_env);
}

int my_unsetenv(my_struct_t *info, char **env)
{
    int *x;
    int i = 0;
    int m = 0;
    int p = 0;
    int y = 0;
    int *alrd;
    int k = 0;
    int v = 0;
    //int d = 0;
    int g = 0;

    if (info->cmd[1] == NULL) {
        my_error("unsetenv: Too few arguments.\n");
        return (0);
    }
    x = search_toun(info);
    store_unenv(info);
    if (x[0] == -1)
        return (-1);
    else {
        for (; info->new_env[y] != 0; y++);
        info->rm_env = malloc(sizeof(char *) * y);
        for (; info->new_env[i] != 0; i++, m++) {
            for (int d = 0; x[d] != -1; d++) {
                    if (i == x[d] && (y - 1) != x[d]) {
                        i++;
                    }
                    if ((y - 1) == x[d] && i == x[d]) {
                        g = 1;
                        break;
                    }
                    info->rm_env[m] = malloc(sizeof(char) * (my_strlen(info->new_env[i]) + 1));
                    for (; info->new_env[i][p] != '\0'; p++)
                        info->rm_env[m][p] = info->new_env[i][p];
                    info->rm_env[m][p] = '\0';
                    p = 0;
            }
            if (g == 1) {
                g = 0;
                break;
            }
        }
        info->rm_env[m] = NULL;
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

void create_next(my_struct_t *info)
{
    int f = 0;

    for (; info->cmd[1][f] != '\0'; f++) {
        info->new_env[info->end_env][f] = info->cmd[1][f];
    }
    info->new_env[info->end_env][f] = '=';
    f += 1;
    if (info->cmd[2] != NULL) {
        for (int i = 0; info->cmd[2][i]; i++, f++)
            info->new_env[info->end_env][f] = info->cmd[2][i];
    }
    info->new_env[info->end_env][f] = '\0';
    info->new_env[info->end_env + 1] = NULL;
    info->end_env += 1;
}

int create_env(my_struct_t *info)
{
    int p = 0;
    int i = 0;
    int f = 0;

    store_tempenv(info);
    info->new_env = malloc(sizeof(char *) * (word_tablen(info->new_env) + 2));
    for (; info->sec_env[i] != NULL; i++) {
        info->new_env[i] = malloc(sizeof(char) *
        (my_strlen(info->sec_env[i]) + 1));
        for (; info->sec_env[i][p]; p++)
            info->new_env[i][p] = info->sec_env[i][p];
        info->new_env[i][p] = '\0';
        p = 0;
    }
    info->end_env = i;
    for (; info->cmd[1][f] != '\0'; f++);
    if (info->cmd[2] != NULL) {
        info->new_env[info->end_env] = malloc(sizeof(char) *
        (my_strlen(info->cmd[2]) + f + 2));
        create_next(info);
    } else {
        info->new_env[info->end_env] = malloc(sizeof(char) * (f + 2));
        create_next(info);
    }
}

int alrd_setenv(my_struct_t *info, int x)
{
    int y = 0;
    int f = 0;

    for (; info->new_env[x][f] != '='; f++);
    if (info->cmd[2] != NULL)
        info->new_env[x] = malloc(sizeof(char) *
        (my_strlen(info->cmd[2]) + f + 2));
    else
        info->new_env[x] = malloc(sizeof(char) * (f + 2));
    for (; y < f; y++) {
        info->new_env[x][y] = info->cmd[1][y];
    }
    info->new_env[x][y] = '=';
    y += 1;
    if (info->cmd[2] != NULL) {
        for (int i = 0; info->cmd[2][i]; i++, y++)
            info->new_env[x][y] = info->cmd[2][i];
    }
    info->new_env[x][y] = '\0';
}