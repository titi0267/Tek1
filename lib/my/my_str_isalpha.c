/*
** EPITECH PROJECT, 2020
** ggg
** File description:
** ggg
*/

int chackal(char c)
{
    if (c > 96 && c < 123) {
        return (1);
    } else if (c > 64 && c < 91) {
        return (2);
    } else {
        return (0);
    }
}

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (chackal(str[i]) == 0) {
            return (0);
        }
    }
    return (1);
}