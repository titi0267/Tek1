/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** separators
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

/*
** Check for separators '&&' or '||'
** Set sub_cmds and return 1 if separator is present and should be executed
** Return 0 if there is no command to execute
** Set cmd to NULL if reached end
** NOTE: sub_cmds should be reset every cmd separated by ';'
*/
int separators(char **cmd, char ***sub_cmds, shell_t *shell)
{
    int i = 0;
    int ret = 0;
    int len;

    if (*cmd == NULL)
        return (0);
    len = my_strlen(*cmd);
    for (; (*cmd)[i] && !((*cmd)[i] == '&' && (*cmd)[i + 1] == '&')
    && !((*cmd)[i] == '|' && (*cmd)[i + 1] == '|'); i++);
    (*cmd)[i] = '\0';
    ret = execute_separator(cmd, sub_cmds, shell);
    if (i == len)
        *cmd = NULL;
    else
        *cmd = *cmd + i + 1;
    return (ret);
}

/*
** Check first char
** If separator is valid, set sub_cmds and return 1
** Else, return 0
*/
int execute_separator(char **cmd, char ***sub_cmds, shell_t *shell)
{
    if ((*cmd)[0] == '&') {
        if (shell->ret == 0) {
            *sub_cmds = split_command_into_subcmds(*cmd + 1);
            return (1);
        } else
            return (0);
    } else if ((*cmd)[0] == '|') {
        if (shell->ret != 0) {
            *cmd = *cmd + 1;
            *sub_cmds = split_command_into_subcmds(*cmd + 1);
            return (1);
        } else
            return (0);
    } else {
        *sub_cmds = split_command_into_subcmds(*cmd);
        return (1);
    }
}