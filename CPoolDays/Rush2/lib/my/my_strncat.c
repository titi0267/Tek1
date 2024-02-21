/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday07-lilou.stoll-metz
** File description:
** my_strncat
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int len = my_strlen(dest);
    int i;

    for (i = 0; i < nb; i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';
    return (dest);
}