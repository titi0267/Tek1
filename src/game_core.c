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

void pos_selection_one(char *pos, infin_number_t *info, char **av, int i)
{
    if (pos[0] >= 'A' && pos[0] <= 'H') {
        info->shot_col[info->round] = pos[0];
    }
    if (pos[1] >= '1' && pos[1] <= '8') {
        info->shot_line[info->round] = pos[0];
    }
    if (pos[0] <= 'A' || pos[0] >= 'H' || pos[1] <= '1' || pos[1] >= '8') {
        my_putstr("wrong position", info);
        converge_one(info);
    }
}

void converge_two(infin_number_t *info)
{
    char *line = NULL;
    size_t len = 0;
    if (info->player_one == 1) {
        my_printf("Waiting for p2's shot\n");
        pause();
    }
    if (info->player_two == 1) {
        my_putstr("attack: ", info);
        if (getline(&line, &len, stdin) == 3) {
            kill(info->process_id2, SIGUSR2);
            kill(info->process_id1, SIGUSR2);
        }
    }
}

void converge_one(infin_number_t *info)
{
    char *line = NULL;
    size_t len = 0;
    if (info->player_one == 1) {
        my_putstr("attack: ", info);
        if (getline(&line, &len, stdin) == 3) {
            kill(info->process_id1, SIGUSR2);
            kill(info->process_id2, SIGUSR2);
        }
    }
    if (info->player_two == 1) {
        my_printf("Waiting for p1's shot\n");
        pause();
    }
}

void handle_sigusr2(int sig, siginfo_t *info, void *context)
{
}

void game_core(infin_number_t *info)
{
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = handle_sigusr2;
    sigaction(SIGUSR2, &sa, NULL);
    converge_one(info);
    converge_two(info);
}