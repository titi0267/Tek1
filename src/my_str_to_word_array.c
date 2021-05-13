/*
** EPITECH PROJECT, 2021
** B-AIA-200-STG-2-1-n4s-elliot.waldvogel
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

int stop_car(char **my_tab)
{
    if (my_strcmp(my_tab[3], "Track Cleared") == 0)
        return (0);
    return (1);
}

void break_car(char **my_tab)
{
    static int stop = 0;

    if (stop_car(my_tab) == 0)
        stop++;
    if (stop >= 1) {
        //dprintf(1, "Car_backwards:1\n");
        dprintf(1, "Car_forward:0.0\n");
        order_line();
        //dprintf(1, "Cycle_wait:10\n");
        dprintf(2, "STOOOOP\n");
    } else if (stop == 0) {
        dprintf(1, "Car_forward:1\n");
        order_line();
        dprintf(1, "Cycle_wait:10\n");
        dprintf(2, "FORWARD\n");
    }
    /*dprintf(2, "SPEED = %i\n", my_tab[4]);
    if (atoi(my_tab[3]) > 30)
        dprintf(1, "CAR_FORWARD:0\n");*/
}

char **malloc_double(char *str, int space)
{
    char **my_tab;
    int p = 0;

    my_tab = malloc(sizeof(char *) * (space + 2));
    for (; p < space; p++)
        my_tab[p] = malloc(sizeof(char) * (my_strlen(str) + 2));
    my_tab[p] = NULL;
    return (my_tab);
}

char **my_str_to_word_array(char *str)
{
    char **my_tab = malloc(sizeof(char *) * 7);
    int space = 1;
    int x = 0;
    int y = 0;

    //dprintf(2, "C'EST LE PRINTF = %s\n", str);
    for (int z = 0; str[z]; z++)
        if (str[z] == ':')
            space++;
    my_tab = malloc_double(str, space);
    for (int i = 0; x <= (space - 1); x++) {
        for (; str[i] != ':' && str[i] != '\n'; i++) {
            my_tab[x][y] = str[i];
            dprintf(2, "%c", my_tab[x][y]);
            y++;
        }
        dprintf(2, ":");
        my_tab[x][y] = '\0';
        i++;
        y = 0;
    }
    dprintf(2, "\n");
    break_car(my_tab);
    return (my_tab);
}