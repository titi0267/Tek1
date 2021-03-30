/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** my_revstr
*/

int get_my_strlen(char *str)
{   int length = 0;

    while (str[length] != '\0') {
        length++;
    }
    return (length);
}

void get_my_swap(char *a, char *b)
{
    char c = *a;

    *a = *b;
    *b = c;
}

char *my_revstr(char *str)
{
    int a = 0;
    int b = get_my_strlen(str) - 1;
    int c = 0;

    while (a < b) {
        get_my_swap(&str[a], &str[b]);
        a = a + 1;
        b = b - 1;
    }
    return (str);
}