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
        for (int d = 25; d != 5; d++) {
            if (duo->store_buf[i][d] == '\n' && i != duo->len)
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
        for (int d = 20; d != 5; d++) {
            if (duo->store_buf[i][d] == '\n' && i != duo->len)
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
        for (int d = 15; d != 5; d++) {
            if (duo->store_buf[i][d] == '\n' && i != duo->len)
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
        for (int d = 10; d != 5; d++) {
            if (duo->store_buf[i][d] == '\n' && i != duo->len)
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
        for (int d = 0; d != 5; d++) {
            if (duo->store_buf[i][d] == '\n' && i != duo->len)
                printf(" ");
            else
                printf("%c", duo->store_buf[i][d]);
        }
    }
    printf("\n");
    digit_two(duo);
    digit_three(duo);
    digit_four(duo);
    digit_five(duo);
}
