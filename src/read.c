/*
** STUMPER
** duo stumper
** file description:
** read
*/

#include "../include/my.h"

/*
static void try_rev(duo_stp_t *duo, int i, char *array)
{
    int e = 0;

    for (int d = 0; duo->line[d] != NULL; d++) {
        for (int f = 0; duo->line[d][f] != '\0'; f++, e++) {
            if (d == i)
                array[e] = my_revstr(duo->line[d][f]);
            else
                array[e] = duo->line[d][f];
        }
    }
}

static void horizontal(duo_stp_t *duo, int i, char *array)
{
    int e = 0;

    for (int d = 0; duo->line[d] != NULL; d++) {
        for (int f = 0; duo->line[d][f] != '\0'; f++, e++) {
            if (d == i)
                array[e] = duo->line[d][f];
            else
                array[e] = duo->line[d][f];
        }
    }
}

void rand_place(duo_stp_t *duo)
{
    int total = 0;
    char *array = malloc(sizeof(char) * (duo->size * duo->size));

    
    for (int i = 0; duo->line[i] != NULL; i++) {
        try_normal(duo, i, array);
        try_rev(duo, i, array);
        for (int d = 0; duo->line[i][d] != '\0'; d++, total++) {
            array[total] = duo->line[i][d];
        }
        array[total] = '\n';
    }
}
*/
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

int all_words(duo_stp_t *duo)
{
    int i = 0;
    int s = 0;

    store_alpha(duo);
    if (duo->size <= duo->line_nbr)
        return (0);
    for (; duo->line[i] != NULL; i++) {
        printf("|");
        for (int d = 0; duo->line[i][d] != '\0'; d++) {
            printf("%c", duo->line[i][d]);
        }
        printf("|\n");
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
