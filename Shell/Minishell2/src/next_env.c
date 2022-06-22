/*
** EPITECH PROJECT, 2021
** next_env by Timothy CONIEL
** File description:
** next_env.c
*/

#include "../include/my.h"

void store_env(my_struct_t *info, char **env)
{
    int i = 0;
    int p = 0;
    info->new_env = malloc(sizeof(char *) * (word_tablen(env) + 1));

    for (; env[i] != NULL; i++) {
        info->new_env[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        for (; env[i][p]; p++) {
            info->new_env[i][p] = env[i][p];
        }
        info->new_env[i][p] = '\0';
        p = 0;
    }
    info->end_env = i;
    info->new_env[i] = NULL;
}

void store_tempenv(my_struct_t *info)
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
