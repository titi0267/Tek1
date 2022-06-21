/*
** EPITECH PROJECT, 2020
** game_core.c for navy by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** game_core
*/

#define _XOPEN_SOURCE 700
#include "../include/my.h"
#include "../include/my_struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
extern int connect;

int pos_selection(char *pos, infin_number_t *info, pos_t *where)
{
    if (pos[0] < 'A' || pos[0] > 'H' || pos[1] < '1' || pos[1] > '8' || 
    my_strlen(pos) > 3) {
        my_putstr("wrong position\n", info);
        return (-1);
    }
    return (0);
}

void handle_sigusr(int sig, siginfo_t *info, void *context)
{
}

void handle_sigusr2(int sig, siginfo_t *info, void *context)
{
}

void data(infin_number_t *info)
{
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    info->game_done = 0;
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = handle_sigusr2;
    sigaction(SIGUSR2, &sa, NULL);
    //connect = info->encrpt;
    kill(info->process_id2, SIGUSR2);
}

void game_core(infin_number_t *info, pos_t *where, map_t *buff)
{
    struct sigaction sa;
    int temp_err1 = -1;
    int temp_err2 = -1;
    sa.sa_flags = SA_SIGINFO;
    info->game_done = 0;
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = handle_sigusr;
    sigaction(SIGUSR1, &sa, NULL);
    while (temp_err1 == -1) {
        temp_err1 = converge_one(info, where, buff);
        if (temp_err1 != -1)
            break;
    }
    while (temp_err2 == -1) {
        temp_err2 = converge_two(info, where, buff);
        if (temp_err2 != -1)
            break;
    }
    data(info);
}