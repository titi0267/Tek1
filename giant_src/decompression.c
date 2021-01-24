/*
** EPITECH PROJECT, 2021
** file_giant.c for antman project by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** file_giant
*/

#include "../include/my.h"
#include "../include/my_struct.h"
#include <stdio.h>
#include <string.h>

int cp_res_to_buff(giant_t *buffer, int pos_res)
{
    for (int i = 7; i >= 0; i--, pos_res++) {
        my_putchar(buffer->char_res[i]);
        buffer->code_binResult[pos_res] = buffer->char_res[i];
    }
    my_putnbr(pos_res);
    return (pos_res);
}

int bin_me(giant_t *buffer, int value, int char_pos)
{
    if (value % 2 == 0)
        buffer->char_res[char_pos] = '1';
    if (value % 2 == 1)
        buffer->char_res[char_pos] = '0';
    return (value);
}

int ascToBin(giant_t *buffer)
{
    buffer->code_binResult = (char *) malloc(sizeof(char) * 32);
    buffer->char_res = malloc(sizeof(char) * 9);
    int i = 0;
    int char_pos = 0;
    int pos_res = 0;
    int value = 0;

    while (i <= buffer->codesize) {
        value = buffer->code[i];
        my_printf("val = %i\n", value);
        while (value > 0) {
            value = bin_me(buffer, value, char_pos);
            value /= 2;
            char_pos++;
        }
        my_putstr(buffer->char_res);
        my_putchar('\n');
        //pos_res = cp_res_to_buff(buffer, pos_res);
        my_putchar('\n');
        char_pos = 0;
        i++;
    }
    buffer->code_binResult[pos_res] = '\0';
    my_putstr(buffer->code_binResult);
    return (0);
}