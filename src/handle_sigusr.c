/*
** EPITECH PROJECT, 2020
** handle_sigusr.c for navy by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** handle_sigusr
*/

#define _XOPEN_SOURCE 700
#include "../include/my.h"
#include "../include/my_struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
extern int connect;

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
        my_printf("Convert(T1): %i\n", connect);
        my_putstr("attack: ", info);
        temp = getline(&line, &len, stdin);
        if (temp != 3 || pos_selection(line, info, where) == -1)
            return (-1);
        if (temp == 3) {
            info->encrpt = encrypt(line, info);
            connect = info->encrpt;
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
            my_printf("Encrypted pos: %i\n", info->encrpt);
            decrypt(info->encrpt, where);
            my_printf("Decrypted col pos: %i\n", where->decrypt_col);
            my_printf("Decrypted lin pos: %i\n", where->decrypt_lin);
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