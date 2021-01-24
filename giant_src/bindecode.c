/*
** EPITECH PROJECT, 2021
** bindecode.c for antman by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** bindecode
*/

#include "../include/my.h"
#include "../include/my_struct.h"
#include <stdio.h>

void bindecode(giant_t *buffer)
{
    buffer->decoding_count = 0;
    int c = 0;
    int d = 0;

    my_putchar('e');
    printf("key = %c", buffer->binkey[c][d]); //pk ce putain de binkey segfault?!
    printf("code = %c", buffer->code[0]);
    for (int i = 0; buffer->code[i] != '\0'; i++) {
        while (buffer->binkey[c][d] != buffer->code[i]) {
            c++;
        }
        my_putchar('e');
        while (buffer->binkey[c][d] == buffer->code[i] && 
        buffer->decoding_count < 8) {
            d++;
            i++;
            buffer->decoding_count++;
        }
        my_putchar(buffer->in_order[c]);
        buffer->decoding_count = 0;
        c = 0;
    }
}