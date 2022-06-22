/*
** EPITECH PROJECT, 2020
** my_str_isprintable.c by Elliot WALDVOGEL
** File description:
** my_str_isprintable
*/

int my_str_isprintable(char const *str)
{
    if (str[0] == '\0')
        return (1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32)
            return (0);
    }
    return (1);
}