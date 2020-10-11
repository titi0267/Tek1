/*
** EPITECH PROJECT, 2020
** my_strcapitalize
** File description:
** my_strcapitalize
*/

char *my_strcapitalize(char *str)
{
    int a = 0;
    int b = 0;

    for (; str[b] != '\0'; b++) {
        if (str[b] >= 65 && str[b] <= 90) {
            str[b] = str[b] + 32;
        }
    }
    for (; str[a] != '\0'; a++) {
        if (((str[a] >= 97 && str[a] <= 122) && str[a - 1] == 32)
            || ((str[a] >= 97 && str[a] <= 122) && str[a] == str[0])
            || (str[a - 1] == 43) || (str[a - 1] == 45))
            str[a] = str[a] - 32;
    }
    return (str);
}