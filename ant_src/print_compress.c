/*
** EPITECH PROJECT, 2021
** print compress by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** print_compress.c
*/

#include "../include/my.h"

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
                    ant->bin_str[f] = ant->fill_sent[e][x];
                    f++;
                }
                break;
            }
        }
        e = 0;
    }
    ant->bin_size = f;
}

int bin_to_ascii(ant_t *ant)
{
    int c = 1;
    int x = 1;
    int sum = 0;
    int y = 0;
    int not_bit = 0;
    int i = 128;
    ant->temp = malloc(sizeof(char) * 9);
    ant->compress = malloc(sizeof(char) * (ant->bin_size / 8) + 1);
    //my_printf("   %i\n", ant->bin_size);
    not_bit = ant->bin_size % 8;
    for (; c < (ant->bin_size + 1) - not_bit; c++) {
        if ((c % 8) != 0) {
            ant->temp[x - 1] = ant->bin_str[c - 1];
            x++;
        }
        if ((c % 8) == 0) {
            ant->temp[x - 1] = ant->bin_str[c - 1];
            for (int f = 0; f < 8; f++) {
                //my_printf("f = %i\n", f);
                if (f == 8 && ant->temp[f] == 1) {
                    i = 1;
                    sum += i;
                }
                if (f == 8)
                    i = 1;
                if (f != 8 && ant->temp[f] == 1) {
                    sum = sum + i;
                }
                i /= 2;
            }
            ant->compress[y] = sum;
            my_printf("%c", ant->compress[y]);
            y++;
            sum = 0;
            i = 128;
            x = 1;
        }
    }
    my_printf("@");
    for (; not_bit != 0; not_bit--) {
        my_printf("%i", ant->bin_str[ant->bin_size - not_bit]);
    }
    my_printf("@");
}
