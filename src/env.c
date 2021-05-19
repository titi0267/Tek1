/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** environnment
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

char *create_variable(char *name, char *value)
{
    char *var = my_strdup(name);
    char *tmp;

    if (!var)
        return (NULL);
    tmp = my_strmerge(var, "=");
    free(var);
    if (value) {
        var = my_strmerge(tmp, value);
        free(tmp);
    } else
        var = tmp;
    return (var);
}

void set_variable(char *name, char *value, char **env)
{
    char *variable = create_variable(name, value);

    for (; *env; env++) {
        if (get_env_name_length(*env) == my_strlen(name) &&
        !my_strcmp(name, *env)) {
            free(*env);
            *env = variable;
        }
    }
}

char **clone_env(char **env, int *size, int bonus_size)
{
    char **new_env;

    *size = 0;
    for (char **cpy = env; *cpy; cpy++, *size += 1);
    new_env = malloc(sizeof(char*) * (*size + bonus_size + 1));
    if (!new_env)
        return (NULL);
    if (bonus_size >= 0) {
        for (int i = 0; i < *size; i++)
            new_env[i] = env[i];
        new_env[*size] = 0;
    }
    return (new_env);
}

char **remove_env_variable(char **args, char **env)
{
    int size = 0;
    int pos = 0;
    char **new_env = clone_env(env, &size, -1);

    for (int i = 0; i < size; i++) {
        if (get_env_name_length(env[i]) != my_strlen(args[1]) ||
        my_strcmp(args[1], env[i])) {
            new_env[pos] = env[i];
            pos++;
        } else
            free(env[i]);
    }
    new_env[pos] = NULL;
    return (new_env);
}

char *get_env_value(char *name, char **env)
{
    int name_len = my_strlen(name);
    int env_name_len;

    for (; *env; env += 1) {
        env_name_len = get_env_name_length(*env);
        if (name_len == env_name_len && !my_strcmp(*env, name))
            return (*env + env_name_len + 1);
    }
    return (NULL);
}