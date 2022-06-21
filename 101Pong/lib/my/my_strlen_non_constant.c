/*
** EPITECH PROJECT, 2020
** my_strlen_non_constant.c by Elliot WALDVOGEL
** File description:
** my_strlen_non_constant
*/

int my_strlen_non_constant(char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
        count++;
    return (count);
}