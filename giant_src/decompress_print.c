/*
** EPITECH PROJECT, 2021
** compress_print_giant.c for antman project Timothy CONIEL & Elliot WALDVOGEL
** File description:
** compress_print_giant
*/

#include "../include/my.h"
#include "../include/my_struct.h"

void calc_x_giant(giant_t *buffer)
{
    if (buffer->diff_wrd > 100 && buffer->diff_wrd < 1000) {
        if (buffer->wrd_nbr < 10)
            my_printf("00%i", buffer->wrd_nbr);
        else if (buffer->wrd_nbr >= 10 && buffer->wrd_nbr < 100)
            my_printf("0%i", buffer->wrd_nbr);
        else
            my_printf("%i", buffer->wrd_nbr);
    }
    if (buffer->diff_wrd < 100 && buffer->diff_wrd >= 10) {
        if (buffer->wrd_nbr < 10)
            my_printf("0%i", buffer->wrd_nbr);
        else
            my_printf("%i", buffer->wrd_nbr);
    }
    if (buffer->diff_wrd < 10)
        my_printf("%i", buffer->wrd_nbr);
}

void diff_wrd_giant(giant_t *buffer)
{
    if (buffer->diff_wrd < 10)
        my_printf("§");
    if (buffer->diff_wrd < 100 && buffer->diff_wrd >= 10)
        my_printf("§§");
    if (buffer->diff_wrd > 100)
        my_printf("§§§");
}

int print_word_giant(giant_t *buffer)
{
    if (select_word_giant(buffer) == -1)
        return (-1);
    buffer->diff_wrd = 0;
    my_printf("%s@", buffer->line[buffer->alrd[0]]);
    for (int i = 0; i < buffer->word; i++) {
        if (i > 0) {
            if (my_strncmp(buffer->line[buffer->alrd[i - 1]],
                buffer->line[buffer->alrd[i]]) != 0) {
                my_printf("%s@", buffer->line[buffer->alrd[i]]);
                buffer->diff_wrd++;
            }
        }
    }
    if (word_place_giant(buffer) == -1)
        return (-1);
    return (0);
}

void print_place_next_giant(giant_t *buffer)
{
    int y = 0;

    for (; buffer->wrd_nbr <= buffer->diff_wrd; buffer->wrd_nbr++) {
        for (; buffer->wrd_plc[buffer->wrd_nbr][y] != -1; y++) {
            if (buffer->wrd_plc[buffer->wrd_nbr][y] == buffer->p) {
                buffer->p++;
                calc_x_giant(buffer);
            }
        }
        y = 0;
    }
    buffer->wrd_nbr = 0;
}

int print_place_giant(giant_t *buffer)
{
    if (print_word_giant(buffer) == -1)
        return (-1);
    buffer->wrd_nbr = 0;
    buffer->p = buffer->wrd_plc[0][0];

    diff_wrd_giant(buffer);
    while (buffer->p < buffer->word)
        print_place_next_giant(buffer);
    return (0);
}