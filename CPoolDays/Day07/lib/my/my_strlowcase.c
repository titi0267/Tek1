/*
** EPITECH PROJECT, 2020
** my_strlowcase
** File description:
** 
*/


char *my_strlowcase(char * str)
{
    int a = 0;

    for (; str[a] != '\0'; a += 1) {
        if (str[a] >= 65 && str[a] <= 90) {
            str[a] = str[a] + 32;
        }
    }
    return (str);
}