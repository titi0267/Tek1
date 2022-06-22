/*
** EPITECH PROJECT, 2020
** lib avec printf clean
** File description:
** my_str_word_array.c
*/

#include "../../include/my.h"
#include <unistd.h>

int find_longest_line(char *str)
{
    int line_length = 0;
    int line = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '\n')
            line_length++;
        else {
            if (line_length > line)
                line = line_length;
            line_length = 0;
        }
    }
    return (line);
}

int get_nb_line(char *buf)
{
    int nb_line = 1;

    for (int i = 0; buf[i] != '\0'; i++)
        if (buf[i] == '\n')
            nb_line++;
    return (nb_line);
}

char **my_malloc(char *buff, char **tab, int nb_line)
{
    for (int i = 0; i < nb_line; i++) {
        tab[i] = malloc(sizeof(char) * (find_longest_line(buff) + 1));
    }
    return (tab);
}

char **str_to_line_array2(char *buff, char **tab)
{
    int x = 0;
    int y = 0;
    int i = 0;

    while (buff[i] != '\0') {
        if (buff[i] == '\n' || buff[i] == '\0') {
            tab[x][y] = '\0';
            x++;
            y = 0;
            i++;
        }
        if (buff[i] != '\n' || buff[i] != '\0') {
            tab[x][y] = buff[i];
            i++;
            y++;
        }
    }
    tab[x][y] = '\0';
    tab[x + 1] = NULL;
    return (tab);
}

char **my_str_to_line_array(char *buff)
{
    int nb_line = get_nb_line(buff);
    char **tab = malloc(sizeof(char *) * (nb_line + 1));

    tab = my_malloc(buff, tab, nb_line);
    tab = str_to_line_array2(buff, tab);
    return (tab);
}