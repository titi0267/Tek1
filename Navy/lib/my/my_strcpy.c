/*
** EPITECH PROJECT, 2020
** my_srtrcpy.c by Elliot WALDVOGEL
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i+1] = '\0';
    return (dest);
}