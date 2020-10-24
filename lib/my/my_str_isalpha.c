/*
** EPITECH PROJECT, 2020
** my_str_isalpha.c by Elliot WALDVOGEL
** File description:
** my_str_isalpha
*/

int my_str_isalpha(char const *str)
{
    if (str[0] == '\0')
        return (1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] <= 64 || (str[i] >= 91 && str[i] <= 96) || 
        (str[i] >= 123 && str[i] <= 127))
            return (0);
    }
    return (1);
}