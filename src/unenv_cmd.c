/*
** EPITECH PROJECT, 2021
** unsetenv command by Timothy CONIEL
** File description:
** unenv_cmd.c
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
        for (; info->new_env[i][p]; p++)
            info->sec_env[i][p] = info->new_env[i][p];
        info->sec_env[i][p] = '\0';
        p = 0;
    }
    info->end_env = i;
    info->sec_env[i] = NULL;
}

int search_unext(my_struct_t *info, int i, int p, int *found_env)
{
    if (info->new_env[i][p + 1] == '=') {
        found_env[info->find_un] = i;
        info->find_un++;
        found_env[info->find_un] = -1;
    }
    return (info->find_un);
}

void search_tounext(my_struct_t *info, int *found_env, int i, int m)
{
    int y = 0;
    int p = 0;
    int g = 0;

    for (; info->cmd[m][y]; y++, p++) {
        for (int f = 0; f <= info->find_un; f++) {
            if (info->new_env[i][p] != info->cmd[m][y] || found_env[f] == i) {
                g = 1;
                break;
            }
        }
        if (g == 1)
            break;
        search_unext(info, i, p, found_env);
    }
}

int *search_toun(my_struct_t *info)
{
    int i = 0;
    int m = 1;
    info->find_un = 0;
    int *found_env = malloc(sizeof(int) * (word_tablen(info->cmd) + 1));

    found_env[0] = -1;
    for (; info->cmd[m] != 0; m++) {
        for (; info->new_env[i]; i++) {
            search_tounext(info, found_env, i, m);
        }
        i = 0;
    }
    found_env[info->find_un] = -1;
    return (found_env);
}