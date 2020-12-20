/*
** EPITECH PROJECT, 2020
** shots_management.c for navy by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** shots_managements
*/

#define _XOPEN_SOURCE 700
#include "../include/my.h"
#include "../include/my_struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
extern int connect;

void mark_ennemy_map(map_t *buff, pos_t *where)
{
    buff->line2[where->decrypt_lin][where->decrypt_col] = 'x';
}

int missed_or_touched(map_t *buff, pos_t *where)
{
    if (my_char_isnum(buff->line[where->decrypt_lin][where->decrypt_col] == 1))
    {
        buff->line[where->decrypt_lin][where->decrypt_col] = 'x';
        return (1);
    }
    if (my_char_isnum(buff->line[where->decrypt_lin][where->decrypt_col] == 0))
    {
        buff->line[where->decrypt_lin][where->decrypt_col] = 'x';
        return (0);
    }
}

void shots_management_ptwo(infin_number_t *info, pos_t *where, map_t *buff)
{
    decrypt(connect, where);
    connect = missed_or_touched(buff, where);
    letter_decrypt(where);
    mark_ennemy_map(buff, where);
    if (connect == 1) {
        my_printf("%c%c: hit\n", where->decrypted_col_char, 
        where->decrypted_lin_char);
    }
    if (connect == 0) {
        my_printf("%c%c: missed\n", where->decrypted_col_char,
        where->decrypted_lin_char);
    }
}

void shots_management_pone(infin_number_t *info, pos_t *where, map_t *buff)
{
    decrypt(connect, where);
    connect = missed_or_touched(buff, where);
    letter_decrypt(where);
    mark_ennemy_map(buff, where);
    if (connect == 1) {
        my_printf("%c%c: hit\n", where->decrypted_col_char, 
        where->decrypted_lin_char);
    }
    if (connect == 0) {
        my_printf("%c%c: missed\n", where->decrypted_col_char,
        where->decrypted_lin_char);
    }
}