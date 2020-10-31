/*
** EPITECH PROJECT, 2020
** gfggg
** File description:
** ggg
*/

int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= 'a' && str[i] <= 'z')) {
            return (0);
        }
    }
    return (1);
}