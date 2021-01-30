/*
** EPITECH PROJECT, 2021
** flags by Timothy CONIEL
** File description:
** flags.c
*/

#include "../include/my.h"

char *keep_alpha(my_struct_t *info)
{
    int p = 0;
    int i = 0;
    int m = 0;
    char *keep_alpha;

    keep_alpha = malloc(sizeof(char) * my_strlen(info->str));
    while (info->str[i] != '\0') {
        if (info->str[i] >= 0 && info->str[i] < 33) {
            i++;
            m = 1;
        } else {
            if (m == 1 && p != 0) {
                keep_alpha[p] = ' ';
                p++;
                m = 0;
            } else {
                keep_alpha[p] = info->str[i];
                p++;
                i++;
                m = 0;
            }
        }
    }
    keep_alpha[p] = '\0';
    return (keep_alpha);
}

void store_cmdline(my_struct_t *info)
{
    int e = 0;
    int p = 0;
    int x = 0;
    int y = 0;

    for (; e < info->cmd_flags; e++) {
        info->cmd[e] = malloc(sizeof(char) * info->flag_len[e] + 10);
        if (e == 0) {
            info->cmd[e][0] = '/';
            p++;
        }
        for (; info->str[x] != '\0' && info->str[x] != ' ';  p++, x++)
            info->cmd[e][p] = info->str[x];
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
        if (info->str[i] != ' ' || info->str[i + 1] != '\0') {
            count++;
        }
        if (info->str[i] == ' ' || info->str[i + 1] == '\0') {
            info->flag_len[f] = count;
            f++;
            count = 0;
        }
    }
    store_cmdline(info);
}
