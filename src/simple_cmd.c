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
    char bin[6] = {'/', 'b', 'i', 'n', '/', '\0'};

    if ((info->cmd_path = malloc(sizeof(char) * my_strlen(info->cmd[0]) + 6))
        == NULL)
        return (-1);
    for (; bin[i] != '\0'; i++)
        info->cmd_path[i] = bin[i];
    for (int x = 0; info->cmd[0][x] != '\0'; x++, i++)
        info->cmd_path[i] = info->cmd[0][x];
    return (0);
}

int store_flags(my_struct_t *info)
{
    int i = 0;

    if ((info->flags = malloc(sizeof(char *) * info->cmd_flags + 8)) == NULL)
        return (-1);
    for (; i < info->cmd_flags; i++) {
        if (i == 0)
            info->flags[i] = info->cmd_path;
        else {
            if (i != info->cmd_flags) {
                info->flags[i] = info->cmd[i];
            }
        }
    }
    info->flags[i] = NULL;
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
        if (execve(info->flags[0], info->flags, NULL) == -1) {
            return (-1);
        }
        return (1);
    } else
        wait(&status);
    return (0);
}