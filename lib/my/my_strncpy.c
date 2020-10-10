/*
** EPITECH PROJECT, 2020
** strcpy
** File description:
** recode str cpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i; i < n; i++) {
        dest[i] = src[i];
    }
    if (dest[i] != '\0') {
        dest[i] = '\0';
    }
    dest[i] = '\0';
    return (dest);
}