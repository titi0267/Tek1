/*
** EPITECH PROJECT, 2020
** task03
** File description:
** string length
*/

int my_strlen(char const *str)
{
    int i = 0;

    while(str[i] != '\0')
        i++;
    return (i);
}
