/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** input
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

char *read_input(char *prefix, int prefix_len)
{
    char *input = get_input(prefix, prefix_len);

    if (!input)
        return (NULL);
    return (input);
}

/*
get the input of the user
prints the prefix $> if necessary
*/
char *get_input(char *prefix, int prefix_len)
{
    char *str = NULL;
    size_t n = 0;
    ssize_t len;

    if (isatty(0))
        write(1, prefix, prefix_len);
    len = getline(&str, &n, stdin);
    if (len == -1) {
        free(str);
        return (NULL);
    }
    if (str[len - 1] == '\n')
        add_char(&str, len - 1, 0);
    else
        add_char(&str, len, 0);
    return (str);
}

int check_input(char **cmds)
{
    if (cmds == NULL)
        return (1);
    else if (cmds[1] == 0 && my_strlen(cmds[0]) == 0)
        return (1);
    return (0);
}