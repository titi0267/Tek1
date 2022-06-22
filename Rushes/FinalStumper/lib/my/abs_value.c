/*
** EPITECH PROJECT, 2020
** abs_value.c for infinadd.c by Elliot WALDVOGEL
** File description:
** abs_value
*/

char *abs_value(char *str)
{
    char *str2;
    int j = 0;

    if (str[0] == '-') {
        for (int i = 1; str[i] != '\0'; i++) {
            str2[j] = str[i];
            j++;
        }
        str2[j] = '\0';
        return (str2);
    }
    else
        return (str);
}