/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** builtins
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

int cd_cmd(char **args, shell_t *shell)
{
    char *home;
    char *path;
    int ret = -1;

    if (args[1] && args[1][0] != '~') {
        if (args[1][0] == '-' && my_strlen(args[1]) == 1)
            ret = change_dir(shell->prev_cd, shell);
        else
            ret = change_dir(args[1], shell);
    } else if ((home = get_env_value("HOME", shell->env))) {
        path = args[1] ? my_strreplace(args[1], '~', home) : home;
        if (!path)
            return (-1);
        ret = change_dir(path, shell);
        if (args[1])
            free(path);
    }
    return (-ret);
}

int env_cmd(char **args, shell_t *shell)
{
    for (char **value = shell->env; *value; value += 1) {
        my_putstr(1, *value);
        write(1, "\n", 1);
    }
    return (0);
}

int setenv_cmd(char **args, shell_t *shell)
{
    char **new_env;
    int size = 0;

    if (args[1] == NULL)
        return (env_cmd(args, shell));
    else if (check_valid_env_name(args[1]))
        return (1);
    if (get_env_value(args[1], shell->env)) {
        set_variable(args[1], args[2], shell->env);
        return (0);
    }
    new_env = clone_env(shell->env, &size, 1);
    new_env[size] = create_variable(args[1], args[2]);
    new_env[size + 1] = NULL;
    free(shell->env);
    shell->env = new_env;
    return (0);
}

int unsetenv_cmd(char **args, shell_t *shell)
{
    char **new_env;

    if (args[1] == NULL) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        return (1);
    }
    if (!get_env_value(args[1], shell->env))
        return (0);
    new_env = remove_env_variable(args, shell->env);
    free(shell->env);
    shell->env = new_env;
    return (0);
}

int exit_cmd(char **args, shell_t *shell)
{
    int value = 0;

    if (shell->in_fd != 0 || shell->out_fd != 1)
        return (0);
    if (args[1]) {
        value = str_to_int(args[1]);
        value = value == -1 ? 0 : value;
    }
    exit_program(value);
    return (0);
}