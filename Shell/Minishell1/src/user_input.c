/*
** EPITECH PROJECT, 2021
** user input by Timothy CONIEL
** File description:
** user_input.c
*/

#include "../include/my.h"

int user_input_gtl(my_struct_t *info, char **env)
{
    int y = 0;
    int p = 0;

    info->str = keep_alpha(info);
    my_count_word(info);
    p = ptr_arr(info, env);
    if (p == -1) {}
    else if (p != 1) {
        y = shell(info);
        if (y == -2)
            return (84);
    }
}

int user_input(my_struct_t *info, char **env)
{
    size_t len = 0;

    while (1) {
            len = 0;
            info->str = NULL;
        if (isatty(STDIN_FILENO))
            my_printf("$> ");
        if (getline(&info->str, &len, stdin) != -1) {
            user_input_gtl(info, env);
        } else
            return (0);
    }
    exit(0);
}
