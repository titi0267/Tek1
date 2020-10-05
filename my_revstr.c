/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** 
*/

int get_strlen(char const *str)
{
    int carac = 0;

    while (str[carac] != '\0')
        carac++;
    return (carac);
}

char *my_revstr(char *str)
{
    int c;
    int a = 0;
    int b = get_strlen(str) - 1;

    while (a < b) {
        c = str[a];
        str[a] = str[b];
        str[b] = c;
        a = a + 1;
        b = b - 1;
    }
    return (str);
}