/*
** EPITECH PROJECT, 2021
** my str to word array by Timothy CONIEL
** File description:
** my_str_to_wordarray.c
*/

#include "my.h"

int *line_len(char *str)
{
    int *line_car = malloc(sizeof(int) * (count_line(str) + 1));
    int y = 0;
    int x = 0;
    int i = 0;

    for (; str[i] != '\0'; i++) {
        x++;
        if (str[i] == '\0' || str[i] == '\n') {
            line_car[y] = x;
            y++;
            x = 0;
        }
    }
    if (str[i - 1] != '\n')
        y += 1;
    line_car[y] = -1;
    return (line_car);
}

char **str_to_wordarray(char *str)
{
    int i = 0;
    int m = 0;
    int p = 0;
    char **lines = malloc(sizeof(char *) * (count_line(str) + 1));
    int *car_line = line_len(str);

    for (; i < count_line(str); i++) {
        lines[i] = malloc(sizeof(char) * (car_line[i] + 1));
        for (; str[m] != '\0' && str[m] != '\n'; p++, m++)
            lines[i][p] = str[m];
        if (str[m] == '\n') {
            lines[i][p] = str[p];
            p++;
        }
        lines[i][p] = '\0';
        m++;
        p = 0;
    }
    lines[i] = NULL;
    return (lines);
}
