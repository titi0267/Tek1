/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** my_strncpy
*/

int my_strlen3(char *src)
{
    int carac = 0;

    while (src[carac] != '\0')
    {
        carac += 1;
    }
    return (carac);
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int carac = my_strlen3(src);

    if (n > carac) {
        for (i = 0; src[i] != '\0' && i < n; i += 1) {
            dest[i] = src[i]; 
        }
        dest[i] = '\0';
        return (dest);
    } 
    else {
        for (i = 0; src[i] != '\0' && i < n; i += 1) {
            dest[i] = src[i];
        }
        return (dest);
    }
}

