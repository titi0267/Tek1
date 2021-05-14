/*
** EPITECH PROJECT, 2021
** user input by Timothy CONIEL
** File description:
** recover user input
*/

#include "../include/my.h"

static int check_win_lose(stumper_t *stp)
{
    int i = 0;

    for (; stp->star[i] != '\n'; i++)
    {
        if (stp->star[i] == '*' && stp->line[stp->word][i] != '*')
            break;
    }
    if (stp->line[stp->word][i] == '\n')
        return (1);
    if (stp->tries == 1)
        return (2);
    return (0);
}

static void compare_letter(stumper_t *stp)
{
    int i = 0;

    for (; stp->line[stp->word][i]; i++) {
        for (int d = 0; stp->str[d]; d++) {
            if (stp->line[stp->word][i] == stp->str[d] && i == d) {
                stp->star[i] = stp->str[d];
            }
            else if (stp->line[stp->word][i] == stp->str[d] && i != d
                     && stp->star[d] == '*' && stp->star[i] == '*')
                stp->star[d] = '?';
        }
    }
    stp->tries--;
}

static int input_core(stumper_t *stp)
{
    int d = 0;

    compare_letter(stp);
    print_first_letter(stp);
    d = check_win_lose(stp);
    rm_question_mark(stp);
    if (d == 1) {
        printf("You won!\n");
        return (1);
    } else if (d == 2) {
        printf("You lost!\n");
        return (1);
    } else
        return (0);
    return (0);
}

static int in_getline(stumper_t *stp, size_t len)
{
    static int error = 0;

    len = 0;
    stp->str = NULL;
    if (error == 0)
        printf("Round %i\n>", stp->rounds);
    else
        printf(">");
    if (getline(&stp->str, &len, stdin) != -1) {
        if (len_error(stp) != 0) {
            error = 1;
            return (0);
        }
        error = 0;
        stp->rounds++;
        if (input_core(stp) == 1)
            return (1);
    } else
        return (2);
    return (0);
}

int get_usr_line(stumper_t *stp)
{
    size_t len = 0;
    int d = 0;

    while (1) {
        d = in_getline(stp, len);
        free(stp->str);
        if (d == 1)
            break;
        if (d == 2)
            return (2);
    }
    return (0);
}
