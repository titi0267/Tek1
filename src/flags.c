/*
** EPITECH PROJECT, 2021
** flags by Timothy CONIEL
** File description:
** flags.c
*/

#include "../include/my.h"

int keep_alpha_next(my_struct_t *info, char *keep_alpha, int i)
{
    static int m = 0;

    if (info->str[i] >= 0 && info->str[i] < 33) {
        i++;
        m = 1;
    } else {
        if (m == 1 && info->p != 0) {
            keep_alpha[info->p] = ' ';
            info->p++;
            m = 0;
        } else {
            keep_alpha[info->p] = info->str[i];
            info->p++;
            i++;
            m = 0;
        }
    }
    return (i);
}

char *keep_alpha(my_struct_t *info)
{
    int i = 0;
    info->p = 0;
    char *keep_alpha;

    keep_alpha = malloc(sizeof(char) * my_strlen(info->str));
    if (info->str[0] == '\0')
        return (keep_alpha);
    while (info->str[i] != '\0')
        i = keep_alpha_next(info, keep_alpha, i);
    keep_alpha[info->p] = '\0';
    return (keep_alpha);
}

int alrd_bin(my_struct_t *info, int p)
{
    if (my_strncmp(info->str, "/bin/") != 0) {
        info->cmd[0][0] = '/';
        info->cmd[0][1] = 'b';
        info->cmd[0][2] = 'i';
        info->cmd[0][3] = 'n';
        info->cmd[0][4] = '/';
        return (p + 5);
    }
    return (p);
}

void store_cmdline(my_struct_t *info)
{
    int e = 0;
    int p = 0;
    int x = 0;

    for (; e < info->cmd_flags; e++) {
        info->cmd[e] = malloc(sizeof(char) * (info->flag_len[e] + 15));
        if (e == 0)
            p = alrd_bin(info, p);
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
