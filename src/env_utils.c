/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** env
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

int check_valid_env_name(char *name)
{
    if (!((*name >= 'A' && *name <= 'Z') || (*name >= 'a' && *name <= 'z'))) {
        write(2, "setenv: Variable name must begin with a letter.\n", 48);
        return (1);
    }
    for (name += 1; *name; name++) {
        if (!((*name >= 'A' && *name <= 'Z') ||
        (*name >= 'a' && *name <= 'z') ||
        (*name >= '0' && *name <= '9') || *name == '_')) {
            write(2, "setenv: Variable name must " \
            "contain alphanumeric characters.\n", 60);
            return (1);
        }
    }
    return (0);
}

int get_env_name_length(char *line)
{
    int len = 0;

    for (; *line && *line != '='; len++, line++);
    return (len);
}

char **copy_env(char **env)
{
    char **new_env;
    int nb = 0;
    char *str_cpy;

    for (char **cpy = env; *cpy; cpy++, nb++);
    new_env = malloc(sizeof(char*) * (nb + 1));
    if (!new_env)
        return (NULL);
    for (int i = 0; i < nb; i++) {
        str_cpy = my_strdup(env[i]);
        if (!str_cpy) {
            free(new_env);
            return (NULL);
        }
        new_env[i] = str_cpy;
    }
    return (new_env);
}