/*
** EPITECH PROJECT, 2020
** my_strncpy.c
** File description:
** copy n characters from a string to another string
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    unsigned char add_border = 1;
    int i = 0;

    while (i < n) {
        dest[i] = src[i];
        if (src[i] == '\0') {
            add_border = 1;
            break;
        }
        i++;
    }
    if (add_border)
        dest[i] = '\0';
    return (dest);
}