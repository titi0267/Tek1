/*
** EPITECH PROJECT, 2021
** main by Timothy CONIEL
** File description:
** main.c
*/
#include "../include/my.h"

void exit_shell(my_struct_t *info)
{
    if (my_strncmp(info->str, "exit\n") == 0)
        exit(info->process_id1);
}

int user_input(my_struct_t *info)
{
    int x = 0;
    size_t len = 0;

    info->str = NULL;
    my_printf("$>");
    if (getline(&info->str, &len, stdin) != -1) {
        my_count_word(info);
        exit_shell(info);
        if (cd(info) != -1)
            user_input(info);
        x = shell(info);
        if (x == -1) {
            for (int i = 0; info->str[i] != '\n'; i++)
                my_putchar(info->str[i]);
            my_printf(": Command not found\n");
            exit(info->process_id1);
        } else if (x == -2) {
            my_printf("Malloc didn't work\n");
            return (-1);
        }
        user_input(info);
    }
    return (0);
}

int main(int ac, char **av)
{
    my_struct_t *info = malloc(sizeof(my_struct_t));

    if (info == NULL || ac > 1 || user_input(info) == -1)
        return (84);
    return (0);
}