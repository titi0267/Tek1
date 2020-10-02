/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday04-timothe.coniel
** File description:
** my_evil_str
*/

int get_strlen(char const *str)
{
    int carac = 0;

    while (str[carac] != '\0')
        carac++;
    return (carac);
}

char *my_evil_str(char *str)
{
    int c;
    int a = 0;
    int b = get_strlen(str) - 1;

    while (a < b) {
        c = str[a];
        str[a] = b;
        str[b] = c;
        a++;
        b--;
    }
    return (str);
}