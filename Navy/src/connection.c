/*
** EPITECH PROJECT, 2020
** connection.c by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** connection
*/

#define _XOPEN_SOURCE 700
#include "../include/my.h"
#include "../include/my_struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
int connect = 0;

void handle_sigusr1(int sig, siginfo_t *info, void *context)
{
    connect = info->si_pid;
}

void display_connexion(int player, infin_number_t *info)
{
    if (player == 0) {
        my_putstr("my_pid: ", info);
        my_put_nbr(info->process_id1, info);
        my_putchar('\n', info);
        my_putstr("waiting for enemy connection...\n\n", info);
    }
    if (player == 1) {
        my_putstr("my_pid: ", info);
        my_put_nbr(info->process_id2, info);
        my_putchar('\n', info);
        my_putstr("successfully connected\n", info);
    }
}

int which_player(char *player, infin_number_t *info)
{
    char *comp1 = "pos1";
    char *comp2 = "pos2";

    for (int i = 0; player[i] != '\0'; i++) {
        if (player[i] != comp1[i] && player[i] != comp2[i]) {
            my_puterr("Wrong pos selected\n");
            return (84);
        }
        if (player[i] == comp1[3]) {
            info->player_one = 1;
            info->process_id1 = getpid();
            return (0);
        }
        if (player[i] == comp2[3]) {
            info->player_two = 1;
            info->process_id2 = getpid();
            return (1);
        }
    }
    return (84);
}

int connection(char **av, infin_number_t *info)
{
    info->process_id1 = 0;
    info->process_id2 = 0;

    for (int i = 1; av[i] != 0; i++) {
        if (my_char_isnum(av[i][0]) == 1) {
            info->process_id1 = my_getnbr(av[i]);
            i++;
        }
        if (which_player(av[i], info) == 84)
            return (84);
        if (which_player(av[i], info) == 0) {
            display_connexion(0, info);
            pause();
            my_printf("enemy connected\n");
        }
        if (which_player(av[i], info) == 1) {
            display_connexion(1, info);
            kill(info->process_id1, SIGUSR1);
        }
    }
    return (0);
}

int assemble(char **av, infin_number_t *info)
{
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    info->player_one = 0;
    info->player_two = 0;

    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = handle_sigusr1;
    sigaction(SIGUSR1, &sa, NULL);
    connection(av, info);
    info->process_id2 = connect;
    return (0);
}