/*
** EPITECH PROJECT, 2020
** hhh
** File description:
** hh
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] > 30 || str[i] < 0)) {
            return (0);
        }
    }
    return (1);
}