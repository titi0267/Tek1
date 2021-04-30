/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int my_strcmp = my_strlen(s1);
    int i = 0;

    if (my_strlen(s1) == 0 && my_strlen(s2) == 0) {
        return (0);
    }
    while (i <= my_strcmp) {
        if (s1[i] == s2[i]) {
            i++;
        }
        if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0') {
            if (s1[i] < s2[i]) {
                return (-1);
            } else if (s1[i] > s2[i]) {
                return (1);
            }
            return (0);
        }
    }
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
