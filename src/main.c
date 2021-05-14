/*
** EPITECH PROJECT, 2021
** B-CPE-210-STG-2-1-stumper5-tom.nomine
** File description:
** main
*/

#include "my.h"
#include <stdlib.h>
#include <stddef.h>

static void free_all(stumper_t *stp)
{
    free(stp->buffer);
    for (int i = 0; stp->line[i] != NULL; i++)
        free(stp->line[i]);
    free(stp->line);
    free(stp->star);
}

static int word_in_star(stumper_t *stp)
{
    int i = my_strlen(stp->line[stp->word]);
    int d = 0;

    if ((stp->star = malloc(sizeof(char) * i)) == NULL)
        return (84);
    for (; stp->line[stp->word][d] != '\n'; d++) {
        stp->star[d] = '*';
    }
    stp->star[d] = '\0';
    return (0);    
}

static void choose_word(stumper_t *stp)
{
    srand(time(NULL));
    stp->word = rand() % stp->line_nbr;
    stp->tries = my_strlen(stp->line[stp->word]);
    stp->rounds = 1;

    printf("*: invalid letter\n");
    printf("?: incorrectly placed letter\n");
    printf("Will you find the secret word?\n");
}

void print_first_letter(stumper_t *stp)
{
    for (int i = 0; stp->star[i] != '\0'; i++) {
        if (i == 0)
            printf("%c",stp->line[stp->word][0]);
        else if (i != 0)
            printf("%c",stp->star[i]);
    }
    printf("\n\n");
}

int main(int ac, char **av)
{
    stumper_t *stp = malloc(sizeof(stumper_t));

    if (stp == NULL || error_core(ac) == 84)
        return (84);
    if (read_map(stp, av) == 84)
        return (84);
    if (store_map(stp) == 84)
        return (84);
    choose_word(stp);
    if (word_in_star(stp) == 84)
        return (84);
    print_first_letter(stp);
    get_usr_line(stp);
    free_all(stp);
    free(stp);
    return (0);
}
