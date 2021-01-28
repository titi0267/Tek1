/*
** EPITECH PROJECT, 2021
** main by Timothy CONIEL
** File description:
** main.c
*/

#define _XOPEN_SOURCE 700
#include "../include/my.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <dirent.h>

void my_count_word(my_struct_t *info)
{
    int e = 0;
    int f = 0;
    int x = 0;
    int p = 0;
    int count = 0;

    info->cmd_flags = 1;
    for (int i = 0; info->str[i] != '\0'; i++) {
        if (info->str[i] == ' ')
            info->cmd_flags++;
    }
    info->flag_len = malloc(sizeof(int) * info->cmd_flags + 1);
    info->cmd = malloc(sizeof(char *) * info->cmd_flags + 8);
    for (int i = 0; info->str[i] != '\0'; i++) {
        if (info->str[i] != ' ' && info->str[i] != '\n') {
            count++;
        }
        else {
            info->flag_len[f] = count;
            f++;
            count = 0;
        }
    }
    for (; e < info->cmd_flags; e++) {
        info->cmd[e] = malloc(sizeof(char) * info->flag_len[e] + 1);
        for (; info->str[x] != '\0' && (info->str[x] != ' ' && info->str[x] != '\n');  p++, x++) {
            info->cmd[e][p] = info->str[x];
        }
        x += 1;
        info->cmd[e][p] = '\0';
        p = 0;
    }
    info->cmd[e] = NULL;
}

/*int shell(void)
{
    char *argv[] = { "/bin/sh", "-c", "env", 0 };
    char *envp[] =
    {
        "HOME=/",
        "PATH=/bin:/usr/bin",
        "TZ=UTC0",
        "USER=timothe",
        "LOGNAME=coniel",
        0
    };
    execve(argv[0], &argv[0], NULL);
}*/

int shell_ls(my_struct_t *info)
{
    int i = 0;
    pid_t pid;
    int status;

    if (my_strncmp(info->cmd[0], "ls") != 0)
        return (-1);
    info->ls_args = malloc(sizeof(char *) * info->cmd_flags + 8);
    for (; i < info->cmd_flags; i++) {
        if (i == 0 && my_strncmp(info->cmd[0], "ls") == 0) {
            info->ls_args[i] = "/bin/ls";
        }
        else {
            if (i != info->cmd_flags) {
                info->ls_args[i] = info->cmd[i];
            }
        }
    }
    info->ls_args[i] = NULL;
    if ((pid = fork()) == -1) {
        perror("fork");
        return (1);
    } else if (pid == 0) {
        if (execve(info->ls_args[0], info->ls_args, NULL) == -1)
            perror("execve");
        return (1);
    } else
        wait(&status);
    return (0);
}

void out_shell(my_struct_t *info)
{
    pid_t pid = getpid();

    if (my_strncmp(info->str, "exit\n") == 0)
        exit(pid);
}

int user_input(my_struct_t *info)
{
    size_t len = 0;

    info->str = NULL;
    my_printf("$>");
    if (getline(&info->str, &len, stdin) != -1) {
        my_count_word(info);
        shell_ls(info);
        out_shell(info);
        if (shell_ls(info) == -1) {
            for (int i = 0; info->str[i] != '\n'; i++)
                my_putchar(info->str[i]);
            my_printf(": Command not found\n");
        }
        user_input(info);
    }
    return 0;
}

int main(int ac, char **av)
{
    my_struct_t *info = malloc(sizeof(my_struct_t));

    if (info == NULL || ac > 1)
        return (84);
    user_input(info);
    return (0);
}