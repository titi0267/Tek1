/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** my_str_isprintable.c
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