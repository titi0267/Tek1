/*
** EPITECH PROJECT, 2020
** my_str_capitalize.c by Elliot WALDVOGEL
** File description:
** my_strcapitalize
*/

char *my_strcapitalize(char *str)
{
    if (str[0] >= 97 && str[0] <= 122) {
        str[0] = str[0] - 32;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            if ((str[i-1] >= 65 && str[i] <= 90) || (str[i-1] >= 48 && str[i-1]
             <= 57))
                str[i] = str[i] + 32;
        }
        if ((str[i] >= 32 && str[i] <= 47) || (str[i] >= 58 && str[i] <= 64) ||
         (str[i] >= 91 && str[i] <= 96) || (str[i] >= 123 && str[i] <= 126)) {
            if (str[i+1] >= 97 && str[i+1] <= 122)
                str[i+1] = str[i+1] - 32;
        }
    }
    return (str);
}