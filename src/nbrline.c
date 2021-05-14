/*
** EPITECH PROJECT, 2020
** nbrline.c
** File description:
** nbrline
*/

#include "../include/my.h"

int nbr_line(char *buffer)
{
    int i = 0;
    int y = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            y++;
        i++;
    }
    return (y);
}

int char_line(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\n') {
        i++;
    }
    return (i + 1);
}

void rm_question_mark(stumper_t *stp)
{
    for (int i = 0; stp->star[i] != '\0'; i++) {
        if (stp->star[i] != '*' && i != 0)
            stp->star[i] = '*';
    }
}

int len_error(stumper_t *stp)
{
    int i = 0;
    int x = 0;

    for (; stp->str[i] != '\n'; i++);
    for (; stp->line[stp->word][x] != '\n'; x++);
    if (x > i) {
        printf("Word too short. Retry.\n");
        return (-1);
    } else if (x < i) {
        printf("Word too long. Retry.\n");
        return (-1);
    }
    return (0);
}

void compare_letter_next(stumper_t *stp, int i, int d)
{
    if (stp->line[stp->word][i] == stp->str[d] && i == d)
        stp->star[i] = stp->str[d];
    for (int e = 0; stp->star[e] != '\0'; e++) {
        if (stp->line[stp->word][i] == stp->str[d] && i != d
            && stp->star[e] == '*')
            stp->star[d] = '?';
    }
/*    if (stp->line[stp->word][i] == stp->str[d] && i != d
        && stp->star[d] == '*' && stp->star[i] == '*')
        stp->star[d] = '?';*/
}
