/*
** EPITECH PROJECT, 2021
** frequency by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** frequency.c
*/

#include "../include/my.h"

void array_par(ant_t *ant)
{
    int c = 0;
    int x = 0;
    static int u = 0;

    for (; ant->car[c] != '\0'; c++) {
        for (; ant->car[x] != '\0'; x++) {
            if (ant->car[c] == ant->car[x])
                break;
            else
            {
                return (1);
            }
            
        }
    }
}

void letter_freq(ant_t *ant)
{
    ant->car = malloc(sizeof(char) * ant->buffer_size);
    int y = 0;
    int c = 0;
    int d = 0;

    for (; ant->str[d] != '\0'; d++)
        ant->car[d] = NULL;
    for (; ant->str[c] != '\0'; c++) {
        for (int x = 0; x <= y; x++) {
            my_printf("1 = %c & 2 = %c\n", ant->car[y], ant->car[x]);
            if (ant->car[y] != ant->car[x]) {
                //my_printf("in if\n");
                y++;
            }
        }
        ant->car[y] = ant->str[c];
    }
    my_printf("y = %i\n", y);
    ant->car[y] = '\0';
}
