/*
** EPITECH PROJECT, 2021
** run simple commands by Timothe CONIEL
** File description:
** simple_cmd.c
*/

#include "../include/my.h"

int my_strcat(my_struct_t *info)
{
    int i = 0;

    if ((info->bin_cat = malloc(sizeof(char *) * info->cmd_nbrp + 16)) == NULL)
        return (-1);
    for (int y = 0; info->bin_path[y] != 0; y++) {
        info->bin_cat[y] = malloc(sizeof(char) * (my_strlen(info->bin_path[y]) + my_strlen(info->cmd[0]) + 1));
            for (; info->bin_path[y][i] != '\0'; i++) {
                info->bin_cat[y][i] = info->bin_path[y][i];
            }
            for (int x = 0; info->cmd[0][x] != '\0'; x++, i++) {
                info->bin_cat[y][i] = info->cmd[0][x];
            }
            info->bin_cat[y][i] = '\0';
            i = 0;
        info->cmd_nbrp = y;
    }
    info->bin_cat[info->cmd_nbrp + 1] = NULL;
    return (0);
}

int store_flags(my_struct_t *info)
{
    int i = 0;
    int p = 0;
    int y = 1;

    if ((info->flags = malloc(sizeof(char *) * (info->cmd_flags + 1))) == NULL)
        return (-1);
    if ((info->cmd_path = malloc(sizeof(char *) * (info->cmd_nbrp + 2))) == NULL)
        return (-1);
            for (int x = 0; info->bin_cat[x] != NULL; x++) {
                info->cmd_path[x] = malloc(sizeof(char) * (my_strlen(info->bin_cat[x]) + my_strlen(info->cmd[0])));
                info->cmd_path[x] = info->bin_cat[x];
            }
    for (; info->cmd[y] != 0; i++, y++) {
        info->flags[y] = malloc(sizeof(char) * (my_strlen(info->cmd[y]) + 1));
        for (; info->cmd[y][p] != '\0'; p++) {
            info->flags[y][p] = info->cmd[y][p];
        }
        info->flags[y][p] = '\0';
        p = 0;
    }
    info->flags[y] = NULL;
    return (0);
}

int my_exec(my_struct_t *info)
{
    int i = 0;

    while (info->bin_cat[i] != NULL) {
        info->flags[0] = malloc(sizeof(char) * (my_strlen(info->bin_cat[i]) + 1));
        info->flags[0] = info->bin_cat[i];
        if (execve(info->flags[0], info->flags, NULL) != -1) {
            break;
        } else
            i++;
    }
    if (info->bin_cat[i] == 0)
        return (-1);
    return (0);
}

int shell(my_struct_t *info)
{
    int status;

    if (my_strcat(info) == -1 || store_flags(info) == -1)
        return (-2);
    if ((info->process_id1 = fork()) == -1) {
        perror("fork");
        return (1);
    } else if (info->process_id1 == 0) {
        if (my_exec(info) == -1)
            return (-1);
        return (1);
    } else
        wait(&status);
    return (0);
}