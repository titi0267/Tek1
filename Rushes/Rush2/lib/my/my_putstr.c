/*
** EPITECH PROJECT, 2020
** task02
** File description:
** put string
*/

int my_putstr(char const *str)
{
    int i = 0;

    while(str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}