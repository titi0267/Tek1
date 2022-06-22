/*
** EPITECH PROJECT, 2020
** my_str_isnum.c by Elliot WALDVOGEL
** File description:
** my_str_isnum
*/

int my_str_isnum(char const *str)
{
    if (str[0] == '\0')
        return (1);
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 0 && str[i] < '-') || (str[i] > '.' && str[i] < '0')
         || str[i] > '9')
            return (0);
    }
    return (1);
}