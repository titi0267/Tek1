/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** compare n characters between two strings
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int difference = 0;

    for (int i = 0; i < n; i++) {
        if (s1[i] == '\0' || s2[i] == '\0'|| difference != 0)
            break;
        difference += (s1[i] - s2[i]);
    }
    return (difference);
}
