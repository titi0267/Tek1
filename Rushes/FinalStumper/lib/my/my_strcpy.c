/*
** EPITECH PROJECT, 2020
<<<<<<< HEAD
** my_strcpy
=======
** my_srtrcpy.c by Elliot WALDVOGEL
>>>>>>> FinalStumper
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
<<<<<<< HEAD
    int i;

    for (i = 0; src[i] != '\0'; i += 1) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
=======
    int i = 0;

    for (; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i+1] = '\0';
>>>>>>> FinalStumper
    return (dest);
}