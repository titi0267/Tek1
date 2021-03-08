/*
** EPITECH PROJECT, 2021
** user input by Timothy CONIEL
** File description:
** recover user input
*/

#include "../include/matchstick.h"

void take_line_input(user_t *user)
{
    user->line = my_getnbr(user->str);

    my_printf("line = %i\n", user->line);
}

int get_user_input(user_t *user)
{
    size_t len = 0;

    while (1) {
        len = 0;
        user->str = NULL;
        my_printf("Your turn:\nLine: ");
        if (getline(&user->str, &len, stdin) != -1) {
            take_line_input(user);
        } else {
            my_puterr("Getline failed.\n");
            return (ERROR);
        }
    }
    return (0);
}
