/*
** EPITECH PROJECT, 2020
** my_strupcase
** File description:
**
*/

char *my_strupcase(char *str)
{
    int a = 0;

    for (; str[a] != '\0'; a += 1) {
        if (str[a] >= 97 && str[a] <= 122) {
            str[a] = str[a] - 32;
        }
    }
    return (str);
}