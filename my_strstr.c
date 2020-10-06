/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** 
*/
#include <string.h>

int my_strlen3(char const *str)
{
    int carac = 0;

    while (str[carac] != '\0')
        carac = carac + 1;
    return (carac);
}

int my_strncmp1(char *str, char const *to_find, int a)
{
    int b = 0;
    int nb = my_strlen3(to_find);

    while (str[a] != '\0' && to_find[b] != '\0') {
        if (str[a] == to_find[b]) {
            a += 1;
            b += 1;
        }
        if (b == nb)
            return (1);
        else if (str[a] < to_find[b])
            return (0);
    }
}

char *my_strstr(char *str , char  const *to_find)
{
    int a = 0;
    int b = 0;
    int res = 0;

        if (to_find[0] == '\0')
            return (str);
    for (; str[a] != '\0'; a += 1) {
        if (str[a] == to_find[b]) {
            res = my_strncmp1(str, to_find, a);
        }
        if (res == 1)
            return (&str[a]);
    }
        return (0);
}