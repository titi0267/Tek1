/*
** EPITECH PROJECT, 2021
** print compress by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** print_compress.c
*/

#include "../include/my.h"

void print_ants(ant_t *ant)
{
    my_printf("@");
    for (; ant->not_bit != 0; ant->not_bit--) {
        my_printf("%c", ant->bin_str[ant->bin_size - ant->not_bit]);
    }
    my_printf("@");
}

int store_sentence(ant_t *ant)
{
    int i = 0;
    int f = 0;
    int e = 0;
    ant->bin_str = malloc(sizeof(char) * (8 * ant->buffer_size) + 1);

    for (; i < ant->buffer_size; i++) {
        for (; ant->reorder[e] != '\0'; e++) {
            if (ant->str[i] == ant->reorder[e]) {
                for (int x = 0; ant->fill_sent[e][x] != -1; x++) {
                    ant->bin_str[f] = ant->fill_sent[e][x] + 48;
                    f++;
                }
                break;
            }
        }
        e = 0;
    }
    ant->bin_size = f;
}

void bin_to_ascii(ant_t *ant)
{
    int i = 128;
    int c = 0;
    int x = 0;
    int sum = 0;
    int f = 0;
    int e = 7;
    int y = 0;
    ant->temp = malloc(sizeof(char) * 9);
    ant->compress = malloc(sizeof(char) * (ant->bin_size / 8) + 1);
    ant->not_bit = ant->bin_size % 8;

    for (;c < ant->bin_size - ant->not_bit; c++) {
        if (c == 0 || c % 8 != 0) {
            ant->temp[x] = ant->bin_str[c];
            x++;
        } else {
            while(e >= 0) {
                if (ant->temp[y] == '1')
                    sum = sum + i;
                i /= 2;
                y++;
                e--;
            }
            x = 0;
            e = 7;
            f++;
            ant->compress[f] = sum;
            my_printf("%c", ant->compress[f]);
            sum = 0;
            y = 0;
            i = 128;
            ant->temp[x] = ant->bin_str[c];
            x++;
        }
    }
    print_ants(ant);
}