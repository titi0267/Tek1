/*
** STUMPER
** duo stumper
** file description:
** read
*/

#include "../include/my.h"

static void store_alpha(duo_stp_t *duo)
{
    int i = 97;

    if ((duo->array = malloc(sizeof(char) * 27)) == NULL)
        exit(84);
    for (int x = 0; x != 26; x++) {
        duo->array[x] = i;
        i++;
    }
}

static void add_car(duo_stp_t *duo, int d)
{
    int s = 0;

    for (int q = d; q < duo->size; q++) {
        s = rand() % 26;
        printf("%c", duo->array[s]);
    }
}

int all_words(duo_stp_t *duo)
{
    int i = 0;
    int s = 0;
    int d = 0;

    store_alpha(duo);
    if (duo->size <= duo->line_nbr)
        return (0);
    for (; duo->line[i] != NULL; i++) {
        printf("|");
        for (; duo->line[i][d] != '\0'; d++) {
            printf("%c", duo->line[i][d]);
        }
        add_car(duo, d);
        printf("|\n");
        d = 0;
    }
    for (; i != duo->size; i++) {
        printf("|");
        for (int x = 0; x != duo->size; x++) {
            s = rand() % 26;
            printf("%c", duo->array[s]);
        }
        printf("|\n");
    }
    return (duo->line_nbr);
}
