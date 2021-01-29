/*
** EPITECH PROJECT, 2021
** flags by Timothy CONIEL
** File description:
** flags.c
*/

#include "../include/my.h"

void store_cmdline(my_struct_t *info)
{
    int e = 0;
    int p = 0;
    int x = 0;

    for (; e < info->cmd_flags; e++) {
        info->cmd[e] = malloc(sizeof(char) * info->flag_len[e] + 1);
        for (; info->str[x] != '\0' && (info->str[x] != ' '
            && info->str[x] != '\n');  p++, x++) {
            info->cmd[e][p] = info->str[x];
        }
        x += 1;
        info->cmd[e][p] = '\0';
        p = 0;
    }
    info->cmd[e] = NULL;
}

void my_count_word(my_struct_t *info)
{
    int f = 0;
    int count = 0;

    info->cmd_flags = my_wordnbr(info->str);
    info->flag_len = malloc(sizeof(int) * info->cmd_flags + 1);
    info->cmd = malloc(sizeof(char *) * info->cmd_flags + 8);
    for (int i = 0; info->str[i] != '\0'; i++) {
        if (info->str[i] != ' ' && info->str[i] != '\n')
            count++;
        else {
            info->flag_len[f] = count;
            f++;
            count = 0;
        }
    }
    store_cmdline(info);
}
