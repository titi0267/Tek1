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

void check_value_counter(giant_t *buffer, int value, int char_pos, int counter)
{
    if (counter < 8 && value == 0) {
        while (counter < 8) {
            buffer->char_res[char_pos] = '0';
            counter++;
        }
    }
}

int cp_res_to_buff(giant_t *buffer, int pos_res)
{
    for (int i = 7; i >= 0; i--, pos_res++)
        buffer->code_binResult[pos_res] = buffer->char_res[i];
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
    while (buffer->i <= buffer->codesize) {
        buffer->value = buffer->code[buffer->i];
        if (buffer->value > 127) {
                buffer->red = buffer->value - 127;
                buffer->value = 127 + buffer->red;
            }
        while (buffer->value > 0) {
            buffer->value = bin_me(buffer, buffer->value, buffer->char_pos);
            buffer->counter++;
            buffer->char_pos++;
            buffer->value /= 2;
            check_value_counter(buffer, buffer->value, buffer->char_pos, 
            buffer->counter);
        }
        buffer->pos_res = cp_res_to_buff(buffer, buffer->pos_res);
        buffer->counter = 0;
        buffer->char_pos = 0;
        buffer->i++;
    }
    buffer->code_binResult[buffer->pos_res] = '\0';
    my_printf("pos after loop = %i\n", buffer->pos_res);
    my_printf("binary sentence size = %i & is at %i\n", 8 * (buffer->codesize +1), buffer->pos_res);
    my_printf("pos 0 = %i\n", buffer->code_binResult[0]);
    //my_putchar('\n');
    //my_putchar(buffer->code_binResult[pos_res - 2853]);
    //my_putchar('\n');
    //my_putchar(buffer->code_binResult[pos_res]);
    for (int i = 0; i < buffer->pos_res; i++) {
        //my_printf("i = %i\n", i);
        my_printf("%c", buffer->code_binResult[i]);
    }
    return (0);
}