/*
** EPITECH PROJECT, 2020
** my_char_is_num.c by Elliot WALDVOGEL
** File description:
** my_char_isnum
*/

int my_char_isnum(char c)
{
    if (c == '\0')
        return (1);
    if ((c >= 0 && c < '-') || (c > '-' && c < '0')
    || c > '9')
        return (0);
    return (1);
}