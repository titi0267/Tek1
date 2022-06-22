/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** return the difference of size between two strings
*/

int my_strcmp(char const *s1, char const *s2)
{
    int difference = s1[0] - s2[0];

    if (difference != 0)
        return (difference);
    for (int i = 0; (s1[i] != '\0' && s2[i] != '\0'); i++) {
        difference = s1[i] - s2[i];
        if (difference != 0) {
            return (difference);
        }
    }
    return (0);
}