/*
** STUMPER
** duo stumper
** file description:
** read
*/

#include "../include/my.h"

void print_digit_five(duo_stp_t *duo)
{
    for (int i = 0; duo->store_buf[i] != NULL; i++) {
        for (int d = 24; d != 28; d++) {
            if (duo->store_buf[i][d] == '\n')
                printf(" ");
            else
                printf("%c", duo->store_buf[i][d]);
        }
    }
    printf("\n");
}

void print_digit_four(duo_stp_t *duo)
{
    for (int i = 0; duo->store_buf[i] != NULL; i++) {
        for (int d = 18; d != 24; d++) {
            if (duo->store_buf[i][d] == '\n')
                printf(" ");
            else
                printf("%c", duo->store_buf[i][d]);
        }
    }
    printf("\n");
}

void print_digit_three(duo_stp_t *duo)
{
    for (int i = 0; duo->store_buf[i] != NULL; i++) {
        for (int d = 12; d != 18; d++) {
            if (duo->store_buf[i][d] == '\n')
                printf(" ");
            else
                printf("%c", duo->store_buf[i][d]);
        }
    }
    printf("\n");
}

void print_digit_two(duo_stp_t *duo)
{
    for (int i = 0; duo->store_buf[i] != NULL; i++) {
        for (int d = 6; d != 12; d++) {
            if (duo->store_buf[i][d] == '\n')
                printf(" ");
            else
                printf("%c", duo->store_buf[i][d]);
        }
    }
    printf("\n");
}

void print_digit_one(duo_stp_t *duo)
{
    for (int i = 0; duo->store_buf[i] != NULL; i++) {
        for (int d = 0; d != 6; d++) {
            if (duo->store_buf[i][d] == '\n')
                printf(" ");
            else
                printf("%c", duo->store_buf[i][d]);
        }
    }
    printf("\n");
    print_digit_two(duo);
    print_digit_three(duo);
    print_digit_four(duo);
    print_digit_five(duo);
}
