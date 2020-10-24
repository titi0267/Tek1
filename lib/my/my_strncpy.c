/*
** EPITECH PROJECT, 2020
** my_strncpy.c by Elliot WALDVOGEL
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int j = my_strlen(src);

    if (n < j) {
        while (i != n) {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
        return (dest);
    }
    else {
        while (src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }
        dest[i+1] = '\0';
        return (dest);
    }
}