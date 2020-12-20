/*
** EPITECH PROJECT, 2020
** encryption.c for navy by Timothy CONIEL & Elliot WALDOGEL
** File description:
** encryption
*/

#define _XOPEN_SOURCE 700
#include "../include/my.h"
#include "../include/my_struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
extern int connect;

void letter_decrypt(pos_t *where)
{
    where->decrypted_lin_char = '0' + (where->decrypt_lin - 1);
    where->decrypted_col_char = 'A' + ((where->decrypt_col / 2) - 1);
    printf("line: %c\n", where->decrypted_lin_char);
    printf("col: %c\n", where->decrypted_col_char);
}

void decrypt(int pos, pos_t *where)
{
    where->decrypt_lin = pos%10;
    where->decrypt_col = (pos - (where->decrypt_lin)) / 10;
}

int encrypt(char *pos, infin_number_t *info)
{
    int encryption = 0;
    int column = char_column(pos[0]);
    int line = char_line(pos[1]);

    column = column*10;
    encryption = column + line;
    return (encryption);
}