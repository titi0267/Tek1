/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** args
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static char **add_elem(char *elem, char **elems, int *nb)
{
    char **new_elems = malloc(sizeof(char*) * (*nb + 2));

    if (!new_elems)
        return (NULL);
    for (int i = 0; i < *nb; i++)
        new_elems[i] = elems[i];
    new_elems[*nb] = elem;
    new_elems[*nb + 1] = 0;
    if (*nb)
        free(elems);
    *nb += 1;
    return (new_elems);
}

char **split_command_into_subcmds(char *str)
{
    char **cmds = NULL;
    char *cmd = NULL;
    int nb_cmds = 0;

    cmd = strtok(str, "|");
    while (cmd) {
        cmds = add_elem(cmd, cmds, &nb_cmds);
        if (!cmds)
            return (NULL);
        cmd = strtok(NULL, "|");
    }
    return (cmds);
}

char **split_command_into_args(char *input)
{
    char **args = NULL;
    char *arg = NULL;
    int nb_args = 0;

    arg = strtok(input, " \t");
    while (arg) {
        args = add_elem(arg, args, &nb_args);
        if (!args)
            return (NULL);
        arg = strtok(NULL, " \t");
    }
    return (args);
}