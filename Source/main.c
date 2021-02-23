/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** main
*/

#include "../include/defender.h"

int main(int ac, char **av)
{
    core_t *core = malloc(sizeof(core_t));
    core->wnd = malloc(sizeof(window_t));

    if (core == NULL || start_error(ac, av) == 84)
        return (84);
    wnd_open(core);
}