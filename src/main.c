/*
** EPITECH PROJECT, 2021
** main by Timothy CONIEL
** File description:
** main.c
*/
#include "../include/my.h"

void exit_shell(my_struct_t *info)
{
    if (my_strncmp(info->str, "exit") == 0) {
        exit(0);
    }
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
    } else
        return (-1);
    return (0);
}

int user_input(my_struct_t *info, char **env)
{
    int x = 0;
    int y = 0;
    size_t len = 0;

    info->str = NULL;
    my_printf("$>");
    while (1) {
    if (getline(&info->str, &len, stdin) != -1) {
        info->str = keep_alpha(info);
        my_count_word(info);
        exit_shell(info);
        y = cd(info);
        my_printf("y = %i\n", y);
        if (y == 0) {
            my_printf("good dir\n");
            user_input(info, env);
            exit(0);
        }
        else if (y == -2) {
            my_error(info->cd_pwd);
            my_error(": No such file or directory.\n");
            user_input(info, env);
            exit(0);
        }
        y = act_pwd(info, env);
        if (y == 0)
            user_input(info, env);
        y = shell(info);
        if (y == -1) {
            my_error(info->str);
            my_error(": Command not found.\n");
            exit(info->process_id1);
        } else if (y == -2) {
            my_error("Malloc didn't work\n");
            return (-1);
        }
        user_input(info, env);
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