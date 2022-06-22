/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** input commands
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

/*splits commands by ;
*/
char **split_commands(char *str)
{
    int nb_cmds = count_char(str, ';') + 1;
    char **cmds = malloc(sizeof(char*) * (nb_cmds + 1));

    if (!cmds)
        return (NULL);
    cmds[nb_cmds] = NULL;
    if (read_commands(str, cmds))
        return (NULL);
    return (cmds);
}

int read_commands(char *str, char **cmds)
{
    char *start = str;
    int len = 0;
    int cmd = 0;

    for (; *str; str++) {
        if (*str == ';') {
            if (add_command(cmds, cmd, start, len))
                return (1);
            start = str + 1;
            len = 0;
            cmd++;
        } else
            len++;
    }
    return (add_command(cmds, cmd, start, len));
}

int add_command(char **cmds, int cmd, char *start, int len)
{
    char *str = malloc(sizeof(char) * (len + 1));

    if (!str)
        return (1);
    my_strncpy(str, start, len);
    str[len] = '\0';
    cmds[cmd] = str;
    return (0);
}