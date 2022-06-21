/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** my_strlen.c
*/

int my_strlen(char const *str)
{
    int j = 0;

    while (str[j] != '\0') {
        j++;
    }
    return (j);
}