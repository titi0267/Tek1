/*
** EPITECH PROJECT, 2020
** revstr
** File description:
** reverse string
*/

char *my_revstr(char *str)
{
    char temp;
    int j = my_strlen (str) - 1;
    int i = 0;

    for (i; i <= j; i ++){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j--;
    }
    return (str);
}