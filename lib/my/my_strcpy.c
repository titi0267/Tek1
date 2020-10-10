/*
** EPITECH PROJECT, 2020
** strcpy
** File description:
** recode str cpy
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i += 1;
    }
    dest[i] = '\0';
    return (dest);
}
