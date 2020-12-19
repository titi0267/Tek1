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

void pos_selection(char *pos, infin_number_t *info, pos_t *where)
{
    if (pos[0] >= 'A' && pos[0] <= 'H') {
        info->shot_col[info->round] = pos[0];
    }
    if (pos[1] >= '1' && pos[1] <= '8') {
        info->shot_line[info->round] = pos[0];
    }
    if (pos[0] <= 'A' || pos[0] >= 'H' || pos[1] <= '1' || pos[1] >= '8' || 
    my_strlen(pos) >= 4) {
        my_putstr("wrong position", info);
        converge_one(info, where);
        converge_two(info, where);
    }
}

void converge_two(infin_number_t *info, pos_t *where)
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
            info->encrpt = encrypt(line, info);
            //printf("%i\n", connect);
            kill(info->process_id2, SIGUSR1);
            kill(info->process_id1, SIGUSR1);
        }
    }
}

void converge_one(infin_number_t *info, pos_t *where)
{
    char *line = NULL;
    int encrpt = 0;
    int decrpt = 0;
    size_t len = 0;
    if (info->player_one == 1) {
        my_putstr("attack: ", info);
        if (getline(&line, &len, stdin) == 3) {
            info->encrpt = encrypt(line, info);
            printf("Encrypted pos: %i\n", info->encrpt);
            decrypt(info->encrpt, where);
            printf("Decrypted col pos: %i\n", where->decrypt_col);
            printf("Decrypted lin pos: %i\n", where->decrypt_lin);
            kill(info->process_id1, SIGUSR1);
            kill(info->process_id2, SIGUSR1);
        }
    }
    if (info->player_two == 1) {
        my_printf("Waiting for p1's shot\n");
        pause();
    }
}

void handle_sigusr(int sig, siginfo_t *info, void *context)
{
}

void handle_sigusr2(int sig, siginfo_t *info, void *context)
{
    connect;
}

void data(infin_number_t *info)
{
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    info->game_done = 0;
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = handle_sigusr2;
    sigaction(SIGUSR2, &sa, NULL);
    connect = info->encrpt;
    //kill(info->process_id1, SIGUSR2);
    kill(info->process_id2, SIGUSR2);
}

void game_core(infin_number_t *info, pos_t *where)
{
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    info->game_done = 0;
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = handle_sigusr;
    sigaction(SIGUSR1, &sa, NULL);
    converge_one(info, where);
    converge_two(info, where);
    data(info);
}