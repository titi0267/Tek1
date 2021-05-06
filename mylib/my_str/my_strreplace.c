/*
** EPITECH PROJECT, 2021
** mystr
** File description:
** my_strreplace
*/

#include <stdlib.h>
#include "my.h"

static int get_char_pos(char *str, int c)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            return (i);
    }
    return (-1);
}

char *my_strreplace(char *str, char c, char *replace)
{
    int len = my_strlen(str);
    int rep_len = my_strlen(replace);
    char *newstr;
    int pos;

    if ((pos = get_char_pos(str, c)) == -1)
        return (my_strdup(str));
    newstr = malloc(sizeof(char) * (len + rep_len));
    if (!newstr)
        return (NULL);
    my_strncpy(newstr, str, pos);
    my_strncpy(newstr + pos, replace, rep_len);
    my_strcpy(newstr + pos + rep_len, str + pos + 1);
    return (newstr);
}