/*
** STUMPER
** duo stumper
** file description:
** read
*/

#include "../include/my.h"

void print_digit(duo_stp_t *duo)
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
}
