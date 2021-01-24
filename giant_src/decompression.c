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
    buffer->code_binResult = (char *) malloc(sizeof(char) * (8 * (buffer->codesize + 1)) + 1);
    buffer->char_res = malloc(sizeof(char) * 9);
    int i = 0;
    int char_pos = 0;
    int pos_res = 0;
    int value = 0;
    int counter = 0;

    while (i <= buffer->codesize) {
        value = buffer->code[i];
        if (value < 0)
            value += 128 + (value * -1);
        while (value > 0) {
            value = bin_me(buffer, value, char_pos);
            counter++;
            char_pos++;
            value /= 2;
            check_value_counter(buffer, value, char_pos, counter);
        }
        pos_res = cp_res_to_buff(buffer, pos_res);
        counter = 0;
        char_pos = 0;
        i++;
    }
    buffer->code_binResult[pos_res] = '\0';
    my_printf("pos after loop = %i\n", pos_res);
    my_printf("binary sentence size = %i & is at %i\n", 8 * (buffer->codesize +1), pos_res);
    my_printf("pos 0 = %i\n", buffer->code_binResult[0]);
    //my_putchar('\n');
    //my_putchar(buffer->code_binResult[pos_res - 2853]);
    //my_putchar('\n');
    //my_putchar(buffer->code_binResult[pos_res]);
    for (int i = 0; i < pos_res; i++) {
        //my_printf("i = %i\n", i);
        my_printf("%c", buffer->code_binResult[i]);
    }
    return (0);
}