/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday07-lilou.stoll-metz
** File description:
** my_strcat
*/

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(dest);
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';
    return (dest);
}