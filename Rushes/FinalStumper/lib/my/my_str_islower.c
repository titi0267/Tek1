/*
** EPITECH PROJECT, 2020
** my_str_islower.c by Elliot WALDVOGEL
** File description:
** my_str_islower
*/

int my_str_islower(char const *str)
{
    if (str[0] == '\0')
        return (1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 97 || str[i] > 122)
            return (0);
    }
    return (1);
}