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

int converge_two(infin_number_t *info, pos_t *where, map_t *buff)
{
    char *line = NULL;
    int temp = 0;
    size_t len = 0;
    if (info->player_one == 1) {
        my_printf("Waiting for p2's shot\n");
        pause();
        shots_management_pone(info, where, buff);
    }
    if (info->player_two == 1) {
        printf("Convert(T1): %i\n", connect);
        my_putstr("attack: ", info);
        temp = getline(&line, &len, stdin);
        if (temp != 3 || pos_selection(line, info, where) == -1)
            return (-1);
        if (temp == 3) {
            info->encrpt = encrypt(line, info);
            connect = info->encrpt;
            //printf("%i\n", connect);
            //shots_management_ptwo(info, where, buff);
            kill(info->process_id2, SIGUSR1);
            kill(info->process_id1, SIGUSR1);
        }
    }
    return (0);
}

int converge_one(infin_number_t *info, pos_t *where, map_t *buff)
{
    char *line = NULL;
    int temp = 0;
    int encrpt = 0;
    int decrpt = 0;
    size_t len = 0;
    if (info->player_one == 1) {
        my_putstr("attack: ", info);
        temp = getline(&line, &len, stdin);
        if (temp != 3 || pos_selection(line, info, where) == -1)
            return (-1);
        if (temp == 3) {
            info->encrpt = encrypt(line, info);
            connect = info->encrpt;
            printf("Encrypted pos: %i\n", info->encrpt);
            decrypt(info->encrpt, where);
            printf("Decrypted col pos: %i\n", where->decrypt_col);
            printf("Decrypted lin pos: %i\n", where->decrypt_lin);
            //shots_management_pone(info, where, buff);
            kill(info->process_id1, SIGUSR1);
            kill(info->process_id2, SIGUSR1);
        }
    }
    if (info->player_two == 1) {
        my_printf("Waiting for p1's shot\n");
        pause();
        shots_management_ptwo(info, where, buff);
    }
    return (0);
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