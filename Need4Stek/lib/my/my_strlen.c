/*
** EPITECH PROJECT, 2020
** my_strlen.c by Elliot WALDVOGEL
** File description:
** my_strlen
*/

int my_strlen(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        count++;
    return (count);
}