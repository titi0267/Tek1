/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** my_strncpy
*/

int my_strlen(char const *src)
{
    int carac = 0;

    while (src[carac] != '\0') 
        carac = carac + 1;
    return (carac);
}

int *my_strncpy(char *dest, char const *src, int n)
{
    int i;
    int b = my_strlen(src);

    if (n > b) {
        for (i = 0; src[i] != '\0'; i += 1) {
            dest[i] = src[i];
        }
        dest[i] = '\0';
        return (dest);
    }
    else {
        for (i = 0; src[i] != '\0'; i += 1) {
            dest[i] = src[i];
        }
        return (dest);
    }
    
}