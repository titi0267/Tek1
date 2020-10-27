/*
** EPITECH PROJECT, 2020
** Cpool day 4
** File description:
** gfs
*/

int my_strlen(char const *str)
{
    int j = 0;

    while (str[j] != '\0') {
        j++;
    }
    return (j);
}