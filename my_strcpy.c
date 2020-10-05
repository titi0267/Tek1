/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    for (int i = 0; src[i] != '\0'; i += 1) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}