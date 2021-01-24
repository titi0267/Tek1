/*
** EPITECH PROJECT, 2021
** bindecode.c for antman by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** bindecode
*/

#include "../include/my.h"
#include "../include/my_struct.h"

int check_next_letter(giant_t *buffer, int c, int d, int i)
{

}

void bindecode(giant_t *buffer)
{
    char a = NULL;
    char b = NULL;
    int count = 0;
    int c = 0;
    int d = 0;

    for (int i = 0; buffer->code[i] != '\0'; i++) {
        while (buffer->binkey[c][d] != buffer->code[i]) {
            c++;
        }
        while (buffer->binkey[c][d] == buffer->code[i] && count < 8) {
            d++;
            i++;
            count++;
        }
        if ((count != 8) && (check_next_letter(buffer, c, d, i) == 1)) {
            my_putchar(buffer->in_order[c]);
        }
        if (count == 8) {
            my_putchar(buffer->in_order[c]);
        }
        count = 0;
    }
}