/*
** EPITECH PROJECT, 2021
** main by Timothy CONIEL
** File description:
** main.c
*/
#include "../include/my.h"

int exit_shell(my_struct_t *info, char **env)
{
    exit(0);
    return (0);
}

/*int act_pwd(my_struct_t *info, char **env)
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
}*/

int envi(my_struct_t *info, char **env)
{
    int i = 0;

    for (; info->new_env[i] != NULL; i++) {
        for (int p = 0; info->new_env[i][p] != '\0'; p++) {
            my_printf("%c", info->new_env[i][p]);
        }
        my_printf("\n");
    }
}

int search(my_struct_t *info, char **env)
{
    int i = 0;

    for (; info->new_env[i]; i++) {
        for (int p = 0; info->new_env[i][p]; p++) {
            if (info->new_env[i][p] == '=')
                return (i);
            if (info->new_env[i][p] != info->cmd[1][p])
                break;
        }
    }
    return (-1);
}

void store_env(my_struct_t *info, char **env)
{
    //static int i = 0;
    int i = 0;
    int p = 0;
    info->new_env = malloc(sizeof(char *) * (word_tablen(env) + 1));
    my_printf("tbl = %i\n", word_tablen(env));

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
    //static int f = 1;
    int i = 0;
    int p = 0;

    info->sec_env = malloc(sizeof(char *) * (word_tablen(info->new_env) + 1));
    for (; info->new_env[i] != NULL; i++) {
        info->sec_env[i] = malloc(sizeof(char) * (my_strlen(info->new_env[i]) + 1));
        for (; info->new_env[i][p]; p++) {
            info->sec_env[i][p] = info->new_env[i][p];
        }
        info->sec_env[i][p] = '\0';
        p = 0;
    }
    info->end_env = i;
    info->sec_env[i] = NULL;
}

int alrd_setenv(my_struct_t *info, int x)
{
    int y = 0;
    int f = 0;

    for (; info->new_env[x][f] != '='; f++);
    my_printf("x = %i\n", x);
    info->new_env[x] = malloc(sizeof(char) * (my_strlen(info->cmd[2]) + f + 2));
    for (; y < f; y++) {
        info->new_env[x][y] = info->cmd[1][y];
        my_printf("%c & y = %i\n", info->new_env[x][y], y);
    }
    info->new_env[x][y] = '=';
    my_printf("%c & y = %i\n", info->new_env[x][y], y);
    y += 1;
    for (int i = 0; info->cmd[2][i]; i++, y++) {
        info->new_env[x][y] = info->cmd[2][i];
    }
    info->new_env[x][y] = '\0';
}

int create_env(my_struct_t *info)
{
    int x = 0;
    int y = 0;
    int p = 0;
    int i = 0;
    int v = word_tablen(info->new_env);
    int f = 0;

    store_tempenv(info);
    //v = word_tablen(info->sec_env);
    //my_printf("%s & f = %i & end = %i\n", info->sec_env[info->end_env -1], f, info->end_env);
    info->new_env = malloc(sizeof(char *) * (v + 2));
    for (; info->sec_env[i] != NULL; i++) {
        info->new_env[i] = malloc(sizeof(char) * (my_strlen(info->sec_env[i]) + 1));
        my_printf("i = %i\n", i);
        for (; info->sec_env[i][p]; p++)
            info->new_env[i][p] = info->sec_env[i][p];
        info->new_env[i][p] = '\0';
        p = 0;
    }
    info->end_env = i;
    for (; info->cmd[1][f] != '\0'; f++);
    info->new_env[info->end_env] = malloc(sizeof(char) * (my_strlen(info->cmd[2]) + f + 2));
    f = 0;
    for (; info->cmd[1][f] != '\0'; f++) {
        info->new_env[info->end_env][f] = info->cmd[1][f];
        my_printf("info : %c f = %i\n", info->new_env[info->end_env][f], f);
    }
    info->new_env[info->end_env][f] = '=';
    my_printf("info : %c& f = %i\n", info->new_env[info->end_env][f], f);
    f += 1;
    for (int i = 0; info->cmd[2][i]; i++, f++) {
        info->new_env[info->end_env][f] = info->cmd[2][i];
        my_printf("info : $%c& f = %i\n", info->new_env[info->end_env][f], f);
    }
    my_printf("end = %i & f = %i\n", info->end_env, f);
    info->new_env[info->end_env][f] = '\0';
    info->new_env[info->end_env + 1] = NULL;
    info->end_env += 1;
    my_printf("%s\n", info->new_env[61]);
}

int my_setenv(my_struct_t *info, char **env)
{
    int x = 0;

    if ((x = search(info, env)) == -1) {
        my_printf("it is -1\n");
        create_env(info);
    } else {
        my_printf("it isn't neg\n");
        alrd_setenv(info, x);
    }
}

int ptr_arr(my_struct_t *info, char **env)
{
    int (*function[4])(my_struct_t *, char **) = {cd, envi, exit_shell, my_setenv};
    char *loul[5] = {"cd", "env", "exit", "setenv", 0};
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
    int y = 0;
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

    store_env(info, env);
    find_path(env, info);
    if (info == NULL || ac > 1 || user_input(info, env) == -1)
        return (84);
    return (0);
}
