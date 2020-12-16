/*
** EPITECH PROJECT, 2020
** connection.c by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** connection
*/

#include "../include/my.h"
#include "../include/my_struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

int which_player(char *player, infin_number_t *info)
{
    char *comp1 = "pos1";
    char *comp2 = "pos2";

    for (int i = 0; player[i] != '\0'; i++) {
        if (player[i] != comp1[i] && player[i] != comp2[i]) {
            my_puterr("Wrong pos selected\n");
            return (84);
        }
    }
    info->process_id = getpid();
}

int connection(int ac, char **av, infin_number_t *info)
{
    for (int i = 1; av[i] != 0; i++) {
        if (my_str_isnum(av[i][0]) == 1)
            i++;
        if (which_player(av[i], info) == 84)
            return (84);
        if (which_player(av[i], info) == 0) {
            display_pid(info);
        }
    }
}