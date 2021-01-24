/*
** EPITECH PROJECT, 2021
** print compress by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** print_compress.c
*/

#include "../include/my.h"

void temporal_bis(ant_t *ant)
{
    ant->temp[ant->w - 1] = ant->bin_str[ant->c - 1];
    for (int f = 0; f < 8; f++) {
        if (f == 8 && ant->temp[f] == 1) {
            ant->i = 1;
            ant->sum += ant->i;
        }
        if (f == 8)
            ant->i = 1;
        if (f != 8 && ant->temp[f] == 1) {
            ant->sum = ant->sum + ant->i;
        }
        ant->i /= 2;
    }
    ant->compress[ant->y] = ant->sum;
    my_printf("%c", ant->compress[ant->y]);
    ant->y++;
    ant->sum = 0;
    ant->i = 128;
    ant->w = 1;
}

int temporal(ant_t *ant, int x, int c)
{
    ant->temp[x - 1] = ant->bin_str[c - 1];
    return (1);
}

void print_ants(ant_t *ant, int not_bit)
{
    my_printf("@");
    for (; not_bit != 0; not_bit--) {
        my_printf("%i", ant->bin_str[ant->bin_size - not_bit]);
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

void bin_to_ascii(ant_t *ant)
{
    ant->y = 0;
    int not_bit = 0;
    ant->i = 128;
    ant->temp = malloc(sizeof(char) * 9);
    ant->compress = malloc(sizeof(char) * (ant->bin_size / 8) + 1);

    not_bit = ant->bin_size % 8;
    for (; ant->c < (ant->bin_size + 1) - not_bit; ant->c++) {
        if ((ant->c % 8) != 0)
            ant->w += temporal(ant, ant->w, ant->c);
        if ((ant->c % 8) == 0)
            temporal_bis(ant);
    }
    print_ants(ant, not_bit);
}
