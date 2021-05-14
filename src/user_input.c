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

    for (; stp->line[stp->word][i] != '\0'; i++) {
        if (stp->line[stp->word][i] != stp->star[i] &&
            stp->line[stp->word][i] != '\n')
            break;
    }
    if (stp->line[stp->word][i] == '\0')
        return (1);
    if (stp->tries == 0)
        return (2);
    return (0);
}

static void compare_letter(stumper_t *stp)
{
    int counter = 0;
    int i = 0;

    for (; stp->line[stp->word][i] != '\0'; i++) {
        if (stp->line[stp->word][i] == stp->str[0] &&
            stp->star[i] == '*') {
            stp->star[i] = stp->str[0];
            counter = -1;
            break;
        } else {
            counter++;
        }
    }
    if (i == counter) {
        printf("%c: is not in this word\n", stp->str[0]);
        stp->tries--;
    }
}

static int input_core(stumper_t *stp)
{
    int d = 0;

    compare_letter(stp);
    printf("%s\n", stp->star);
    printf("Tries: %i\n\n", stp->tries);
    d = check_win_lose(stp);
    if (d == 1) {
        printf("Congratulations!\n");
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
    len = 0;
    stp->str = NULL;
    printf("Round %i\n>", stp->rounds);
    if (getline(&stp->str, &len, stdin) != -1) {
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
