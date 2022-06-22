/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** my_strcpy.c
*/

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i] != 0; i++) {
        dest[i] = src[i];
    }
    dest[i] = 0;
    return (dest);
}