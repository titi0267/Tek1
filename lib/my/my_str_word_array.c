/*
** EPITECH PROJECT, 2020
** lib avec printf clean
** File description:
** my_str_word_array.c
*/

#include "../../include/my.h"
#include <unistd.h>

int find_longest_word(char *str)
{
    int line_length = 0;
    int line = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\n')
            line_length++;
        else {
            if (line_length > line)
                line = line_length;
            line_length = 0;
        }
    }
    return (line);
}

int get_nb_words(char *buf)
{
    int nb_words = 0;

    for (int i = 0; buf[i + 1] != '\0'; i++) {
        if ((buf[i] != ' ' && buf[i] != '\t') &&
        (buf[i + 1] == ' ' || buf[i + 1] == '\t' || buf[i + 1] == '\0'))
            nb_words++;
    }
    return (nb_words);
}

char **my_str_to_word_array2(char *str, char **tab)
{
    int column = 0;
    int array = 0;
    int i = 0;

    while (str[i] != '\0') {
        while (str[i] == ' ' || str[i] == '\t') {
            i++;
            array = 0;
        }
        while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0') {
            tab[column][array] = str[i];
            i++;
            array++;
        }
        tab[column][array] = '\0';
        column++;
    }
    tab[column] = NULL;
    return (tab);
}

char **my_malloc(char *buff, char **tab, int nb_word)
{
    for (int i = 0; i < nb_word; i++) {
        tab[i] = malloc(sizeof(char) * (find_longest_word(buff) + 1));
    }
    return (tab);
}

char **my_str_to_word_array(char *str)
{
    int nb_words = get_nb_words(str);
    char **tab = malloc(sizeof(char *) * (nb_words + 3));

    tab = my_malloc(str, tab, nb_words);
    tab = my_str_to_word_array2(str, tab);
    return (tab);
}

